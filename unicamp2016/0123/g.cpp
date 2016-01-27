#include <bits/stdc++.h>
#define MAX 1005
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

char maze[MAX][MAX];
int d[MAX][MAX], r, c, dex[4*MAX];
int x[5] = {1, -1, 0, 0}, y[5] = {0, 0, 1, -1};
pii ex[4*MAX], st;
bool f;
queue<pii> q;

bool pode (int x, int y) {
    if (x >= 0 && x < r && y >= 0 && y < c && maze[x][y] != '#') return true;
    return false;
}

bool end (int x, int y) {
    if (x == 0 || x == r-1 || y == 0 || y == c-1) return true;
    return false;
}

void bfs () {
    while (!q.empty ()) {
        pii n = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii p;
            p.ff = n.ff+x[i], p.ss = n.ss+y[i];
            if (pode (p.ff, p.ss) && d[p.ff][p.ss] > d[n.ff][n.ss]+1) {
                d[p.ff][p.ss] = d[n.ff][n.ss]+1;
                q.push (p);
            }
        }
    }
}

int main () {
    scanf ("%d %d", &r, &c);
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf (" %c", &maze[i][j]);
            d[i][j] = INT_MAX;
            if (maze[i][j] == 'J') st = pii (i, j);
            if (maze[i][j] == 'F') {
                q.push (pii (i, j));
                d[i][j] = 0;
            }
            if (end (i, j) && (maze[i][j] == '.' || maze[i][j] == 'J')) {
                ex[k].ff = i, ex[k++].ss = j;
            }
        }
    }
    bfs ();
    for (int i = 0; i < k; i++)
        dex[i] = d[ex[i].ff][ex[i].ss];
    d[st.ff][st.ss] = 0;
    q.push (st);
    bfs ();
    int ans = INT_MAX;
    for (int i = 0; i < k; i++) {
        if (dex[i] > d[ex[i].ff][ex[i].ss])
            ans = min (ans, d[ex[i].ff][ex[i].ss]+1);
    }
    if (ans == INT_MAX) printf ("IMPOSSIBLE\n");
    else printf ("%d\n", ans);
}
