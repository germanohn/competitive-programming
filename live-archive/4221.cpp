#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

struct figura {
    int x, y, tipo, ok;
    figura (int a, int b, int t) {
        x = a;
        y = b;
        tipo = t;   // 1: ponto, 2: reta
    }
};

int n, m;
vector<figura> hor, ver;
map<int, int> mark;
set<pii> ok;

bool cmp1 (figura a, figura b) { return a.y < b.y; }

bool cmp2 (figura a, figura b) { return a.x < b.x; }

bool cmp3 (figura a, figura b) { return a.y > b.y; }

bool cmp4 (figura a, figura b) { return a.x > b.x; }

void lineSweep (vector<figura> v, int sentido) {
    int curLine = 0;
    mark.clear ();
    for (int i = 0; i < v.size (); i++) {
        if (v[i].tipo == 1) {
            int val;
            if (sentido == 1) // vertical, entao conta o y
                val = v[i].y;
            else              // horizontal, entao conta o x
                val = v[i].x;
            pii pto = pii (v[i].x, v[i].y);
            if (mark[val] != curLine) 
                ok.insert (pto);
            mark[val] = curLine;
        } else {
            curLine++;
        }
    }
}

int main () {
    while (scanf ("%d %d", &n, &m)) {
        ok.clear ();
        mark.clear ();
        hor.clear ();
        ver.clear ();
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf ("%d %d", &a, &b);
            hor.pb (figura (a, b, 1));
            ver.pb (figura (a, b, 1));
        }
        for (int j = 0; j < m; j++) {
            char var, c;
            int val;
            scanf (" %c%c%d", &var, &c, &val);
            if (var == 'x') {
                ver.pb (figura (val, 0, 2));
            } else {
                hor.pb (figura (0, val, 2));
            }
        }
       
        sort (hor.begin (), hor.end (), cmp1);
        sort (ver.begin (), ver.end (), cmp2);
        // esq para direita 
        lineSweep (ver, 1);
        // baixo para cima
        lineSweep (hor, 2); 
        sort (hor.begin (), hor.end (), cmp3);
        sort (ver.begin (), ver.end (), cmp4);
        // direita para esq
        lineSweep (ver, 1);
        // cima para baixo
        lineSweep (hor, 2);
        int ans = ok.size ();
        printf ("%d\n", ans);
    }
}

