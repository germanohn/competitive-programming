#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 55;

int n, m, k;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool seen[MAX][MAX];
char grid[MAX][MAX];
vector<pair<int, pii> > comp;

bool can (int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= m)
       return false;
    return true; 
}

int bfs (int row, int col, int ch) {
    queue<pii> q;
    q.push (pii (row, col));
    seen[row][col] = true;
    int cont = 0;
    bool bound = false;
    while (!q.empty ()) {
        pii x = q.front ();
        q.pop ();
        cont++;
        if (x.ff == 0 || x.ff == n-1 || x.ss == 0 || x.ss == m-1) 
            bound = true;

        if (ch) 
            grid[x.ff][x.ss] = '*';

        for (int i = 0; i < 4; i++) {
            pii nx = pii (x.ff + dx[i], x.ss + dy[i]);
            if (grid[nx.ff][nx.ss] == '*') continue;

            if (can (nx.ff, nx.ss) && !seen[nx.ff][nx.ss]) {
                seen[nx.ff][nx.ss] = true;
                q.push (nx);
            }
        }
    }
    if (bound) return 0;
    return cont;
}

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf (" %c", &grid[i][j]);
        }
    }

    int cont_comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!seen[i][j] && grid[i][j] == '.') {
                int qtd = bfs (i, j, 0);
                if (qtd != 0)
                    cont_comp++, comp.pb (mp (qtd, pii (i, j)));
            }
        }
    }

    sort (comp.begin (), comp.end ());
    memset (seen, 0, sizeof seen);

    int destroy = cont_comp - k;
    int ans = 0;
    for (int i = 0; i < destroy; i++) {
        pii x = comp[i].ss;
        ans += bfs (x.ff, x.ss, 1);
    }
   
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf ("%c", grid[i][j]);
        }
        printf ("\n");
    }
}

