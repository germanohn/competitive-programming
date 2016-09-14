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

const int MAX = 105;

int n, m, ans, ini, fim;
bool seen[MAX][MAX];
vector<pii> adj[MAX];

void dfs (int u, int color) {
    seen[u][color] = true;
    if (u == fim) {
        ans++;
        return;
    }
    for (pii v : adj[u]) {
        if (!seen[v.ff][v.ss] && v.ss == color) 
            dfs (v.ff, color);    
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf ("%d %d %d", &u, &v, &c);
        adj[u].pb (pii (v, c));
        adj[v].pb (pii (u, c));
    }

    int q;
    scanf ("%d", &q);
    while (q--) {
        ans = 0;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) 
                seen[i][j] = false;
        scanf ("%d %d", &ini, &fim);     
        for (int i = 1; i <= m; i++) 
            dfs (ini, i);
        printf ("%d\n", ans);
    }
}

