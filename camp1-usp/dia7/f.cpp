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

const int MAX = 25;
const int inf = 1e9;

int n, m;
int dis[MAX][MAX];
// i = 0 up, i = 1 right, i = 2 down, i = 3 left   
int dRow[4] = {-1, 0, 1, 0}; 
int dCol[4] = {0, 1, 0, -1};
char grid[MAX][MAX];
pii st, end;

bool can (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#') return false;
    return true;
}

int calc (pii x, int dir) {
    int d = 0;
    pii nx = pii (x.ff + dRow[dir], x.ss + dCol[dir]);
    while (can (nx.ff, nx.ss)) {
        nx = pii (nx.ff + dRow[dir], nx.ss + dCol[dir]);
        d++;
    }
    return d;
}

void bfs () {
    queue<pii> q;
    q.push (st);
    dis[st.ff][st.ss] = 0;
    while (!q.empty ()) {
        pii x = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            int d = calc (x, i);
            d = d - d/2;
            pii nx = pii (x.ff + d*dRow[i], x.ss + d*dCol[i]);
            if (dis[nx.ff][nx.ss] > dis[x.ff][x.ss] + 1) {
                dis[nx.ff][nx.ss] = dis[x.ff][x.ss] + 1;
                q.push (nx);
            }
        }
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf (" %c", &grid[i][j]);        
            if (grid[i][j] == 'S')
                st = pii (i, j);
            else if (grid[i][j] == 'T')
                end = pii (i, j);
            dis[i][j] = inf;
        }
    }
    bfs ();
    if (dis[end.ff][end.ss] != inf) printf ("%d\n", dis[end.ff][end.ss]);
    else printf ("-1\n");
}

