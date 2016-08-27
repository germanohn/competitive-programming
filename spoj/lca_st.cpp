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

const int MAX = 1005;

int t, n, m, q;
int prof[MAX], lc[MAX][30];
vector<int> adj[MAX];

int lca (int u, int v) {
    if (prof[u] < prof[v]) swap (u, v);
    for (int i = 20; i >= 0; i--) {
        if (prof[lc[u][i]] >= prof[v])
            u = lc[u][i];
    } 
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) {
        if (lc[u][i] != lc[v][i]) {
            u = lc[u][i];
            v = lc[v][i];
        }
    } 
    u = lc[u][0];
    return u;
}

void dfs (int u, int p, int dis) {
    lc[u][0] = p;
    for (int i = 1; i <= 20; i++) 
        lc[u][i] = lc[lc[u][i-1]][i-1];
    for (int v : adj[u]) 
        if (v != p) {
            prof[v] = dis+1;
            dfs (v, u, dis+1);    
        }
}

int main () {
    int caso = 1;
    scanf ("%d", &t);
    while (t--) {
        for (int i = 0; i < n; i++) adj[i].clear ();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) 
                lc[i][j] = 0;
        }
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &m);
            int v;
            while (m--) {
                scanf ("%d", &v);
                v--;
                adj[i].pb (v);
                adj[v].pb (i);
            }
        }
        prof[0] = 0;
        dfs (0, 0, 0);
        printf ("Case %d:\n", caso++);
        scanf ("%d", &q);
        while (q--) {
            int u, v;
            scanf ("%d %d", &u, &v);
            int ans = lca (u-1, v-1);
            printf ("%d\n", ans+1);
        }
    }   
}

