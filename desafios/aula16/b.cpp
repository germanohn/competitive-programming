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

int dfs (int u, int mini) {
    seen[u] = tempo;
    if (u == 2) return mini;
    for (int i = 0; i < adj[u].size (); i++) {
        edge ed = edges[adj[u][i]];
        if (seen[ed.to] < tempo && ed.c - ed.f > 0) {
            if (int up = dfs (ed.to, min (mini, ed.c - ed.f))) {
                edges[adj[u][i]].f += up;
                edges[adj[u][i] ^ 1].f -= up;
                return up;
            }
        }
    }
    return 0;
}

int ford_fulkerson () {
    int flow = 0;
    while (int up = dfs (1, INT_MAX)) {
        flow += up;
        tempo++;
    }
    return flow;
}

void add_edge (int u, int v, int c, int rc) {
    edges[cur].to = u, edges[cur].c = c, edges[cur].f = 0;
    adj[u].pb (cur++);
    edges[cur].to = v, edges[cur].c = rc, edges[cur].f = 0;
    adj[v].pb (cur++);
} 

void dfs_res (int u) {
    seen_res[u] = true;
    for (int i = 0; i < adj[u].size (); i++) {
        edge ed = adj[u][i];
        if (ed.c == ed.f || seen_res[ed.to]) continue;
        dfs_res (ed.to);
    }
}

int main () {
    while (scanf (" %d %d", &n, &m)) {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf (" %d %d %d", &u, &v, &c);
            add_edge (u, v, c, 0);
        }

        int ans = ford_fulkerson ();

        dfs_res (1);
    }
}

