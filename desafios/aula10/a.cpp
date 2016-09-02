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

const int MAX = 255;
const int MAXN = 100000;

int n, m;
int freq[MAXN];
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};
int grid[MAX][MAX];
bool seen[MAX][MAX];

bool can (pii x) {
    if (x.ff < 0 || x.ff >= n || x.ss < 0 || x.ss >= m || grid[x.ff][x.ss] == 0) return false;
    return true;
}

int bfs (int row, int col) {
    queue<pii> q;
    q.push (pii (row, col));
    seen[row][col] = true;
    int size = 1;
    while (!q.empty ()) {
        pii x = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii nx = pii (x.ff+d_row[i], x.ss+d_col[i]);
            if (can (nx) && !seen[nx.ff][nx.ss]) {
                seen[nx.ff][nx.ss] = true;
                size++;
                q.push (nx);
            }
        }
    }
    return size;
}

int main () {
    while (scanf ("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;
        memset (freq, 0, sizeof freq);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                seen[i][j] = false;
                scanf ("%d", &grid[i][j]);
            }
        }

        int cont = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !seen[i][j]) { 
                    int size = bfs (i, j);
                    cont++;
                    freq[size]++;
                }
            }
        }

        printf ("%d\n", cont);
        for (int i = 1; i <= n*n; i++) 
            if (freq[i]) printf ("%d %d\n", i, freq[i]);
    }
}

