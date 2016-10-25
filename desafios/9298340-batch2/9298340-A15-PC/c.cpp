#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct edge {
    int to, c, f;
};

const int MAX = 205;

int n, m, cur, tempo, s, t;
int seen[MAX], a[MAX], b[MAX], edge_t[MAX];
int ans[MAX][MAX];
edge edges[4*MAX*MAX];
vector<int> adj[MAX];

int dfs (int u, int mini) {
    seen[u] = tempo;
    if (u == t) return mini;
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
    while (int up = dfs (s, INT_MAX)) {
        flow += up;
        tempo++;
    }
    return flow;
}

void add_edge (int u, int v, int c, int rc) {
    edges[cur].to = v, edges[cur].c = c, edges[cur].f = 0;
    adj[u].pb (cur++);
    edges[cur].to = u, edges[cur].c = rc, edges[cur].f = 0;
    adj[v].pb (cur++);
}

int main () {
    scanf (" %d %d", &n, &m);
    
    s = 0, t = 2*n + 1;
    cur = 0, tempo = 1;

    for (int i = 1; i <= n; i++) {
        scanf (" %d", &a[i]);
        add_edge (s, i, a[i], 0);
        add_edge (i, n+i, a[i], 0);
    }

    for (int i = 1; i <= n; i++) {
        scanf (" %d", &b[i]);
        edge_t[n+i] = cur;
        add_edge (n+i, t, b[i], 0);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf (" %d %d", &u, &v);
        add_edge (u, v+n, a[u], 0);
        add_edge (v, u+n, a[v], 0);
    }

    int max_flow = ford_fulkerson ();

    bool ok = true;
    for (int i = 1; ok && i <= n; i++) {
        int qtd_out = 0;
        for (int j = 0; j < adj[i].size (); j++) {
            edge ed = edges[adj[i][j]];
            if (ed.to == s) continue;
            qtd_out += ed.f;
            ans[i][ed.to] = ed.f;
        }
        ans[i][i] = a[i] - qtd_out;
    
        if (((a[i] - qtd_out) + edges[edge_t[n+i]].f) != b[i])
          ok = false;  
    }

    if (ok) {
        printf ("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1+n; j <= 2*n; j++) {
                printf ("%d ", ans[i][j]);
            }
            printf ("\n");
        }
    } else {
        printf ("NO\n");
    }
}

