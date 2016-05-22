#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;
const int inf = 1000000000;

struct pos {
    int x, y, mask;
    pos (int a, int b, int c) {
        x = a;
        y = b;
        mask = c;
    }
};

int n, d[MAX][MAX], cont, qok; 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char A[MAX][MAX], mark[MAX][MAX];

int convert (char c) {
    int a;
    if (islower (c)) {
        a = c - 'a';
    } else {
        a = c - 'A' + 10;
    }
    return a;
}

bool can (int x, int y) {
    if (x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
        return true;
    return false;
}

void bfs () {
    queue<pos> q;
    int a = convert (A[0][0]);
    q.push (pos (0, 0, (1 << a)));
    d[0][0] = 1;
    while (!q.empty ()) {
        pos cel = q.front ();
        //printf ("agora cel.x %d cel.y %d cel.mask %d\n", cel.x, cel.y, cel.mask);
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pos nw = (pos (cel.x + dx[i], cel.y + dy[i], cel.mask));
            if (can (nw.x, nw.y)) {
                a = convert (A[nw.x][nw.y]);
                bool ok = true;   
                if (a >= 10) {
                    int aux = a - 10;
                    if ((1 << aux) & cel.mask != 0)
                        ok = false;
                } else {
                    int aux = a + 10;
                    if ((1 << aux) & cel.mask != 0)
                        ok = false;
                }
                if (!ok)
                    qok++;
                cont++;
                // se ta ok com a restricao e a distancia vai diminuir
                if (ok && d[nw.x][nw.y] > d[cel.x][cel.y] + 1) {
                    if (cel.mask & (1 << a) == 0)
                        nw.mask |= (1 << a);
                    d[nw.x][nw.y] = d[cel.x][cel.y] + 1;
                    q.push (pos (nw.x, nw.y, nw.mask));
                }
            }
        }    
    }
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        qok = cont = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf (" %c", &A[i][j]);
            }
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                d[i][j] = inf;
        bfs ();
        printf ("ok %d cont %d\n", qok, cont);
        if (d[n-1][n-1] == inf) {
            printf ("-1\n");
        } else {
            printf ("%d\n", d[n-1][n-1]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                printf ("%c", mark[i][j]);
            printf ("\n");
        }

    }
}

