#include <bits/stdc++.h>
#define debug(args...) fprintf (stderr, args)
#define ff first
#define ss second
#define MAX 1005
using namespace std;
typedef pair<int, int> pii;

struct tipo {
    int x, y, w, s;//x e y posicao w distancia da saida s ate posicao x, y
};

struct no {
    int fire, joe;
};

int r, c, d[MAX][MAX];
int x[5] = {0, 0, 1, -1}, y[5] = {1, -1, 0, 0};
char A[MAX][MAX];
no s[4*MAX];
queue<tipo> q;

bool pode (int a, int b) {
    if (a >= 0 && a < r && b >= 0 && b < c && A[a][b] != '#') return true;
    return false;
}

bool end (int a, int b) {
    if ((a == 0 || a == r-1 || b == 0 || b == c-1) && A[a][b] != 'J' && A[a][b] != 'F') return true;
    return false;
}

void bfs () {
    while (!q.empty ()) {
        tipo p = q.front (), n;
        q.pop ();
        char pos = A[p.x][p.y];
        if (pos == 'F') {
            s[p.s].fire = p.w;
            continue;
        }
        else if (pos == 'J') {
            s[p.s].joe = p.w;
            continue;
        }
        debug ("pra esse par p.x %d p.y %d temos \n", p.x, p.y);
        for (int i = 0; i < 4; i++) {
            n.x = p.x+x[i], n.y = p.y+y[i];
            debug ("A  %c  dentro do for bx %d by %d\n", A[n.x][n.y], n.x, n.y);
            if (pode (n.x, n.y) && !end (n.x, n.y) && d[p.x][p.y]+1 < d[n.x][n.y]) {
                debug ("ENTROU bx %d by %d\n", n.x, n.y);
                d[n.x][n.y] = d[p.x][p.y]+1;
                n.w = p.w+1, n.s = p.s;
                q.push (n);
            }
        }
    }
}

int main () {
    int k = 0, jx, jy;
    char cc;
    bool f = false;
    scanf (" %d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf (" %c", &cc);
            A[i][j] = cc;
            if (cc == 'J') jx = i, jy = j;
            if (end (i, j) && cc == '.') {
                debug ("saidas i %d j %d \n", i, j);
                f = true;
                tipo aux;
                d[i][j] = 0;
                aux.x = i, aux.y = j, aux.w = 1, aux.s = k;
                q.push (aux);
                s[k].fire = INT_MAX, s[k++].joe = INT_MAX;
            }
            else d[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf ("%d ", d[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    debug ("Imprimi as d\n");
    bfs ();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf ("%d ", d[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    int mi = INT_MAX;
    if ((jx == 0 || jy == 0 || jx == r-1 || jy == c-1) && !f) {
        printf ("1\n");
        return 0;
    }
    f = false;
    printf ("k %d\n", k);
    for (int i = 0; i < k; i++) {
        if (s[i].joe <= s[i].fire) {
            mi = min (mi, s[i].joe);
            f = true;
        }
    }
    if (f) printf ("%d\n", mi);
    else printf ("IMPOSSIBLE\n");
}
