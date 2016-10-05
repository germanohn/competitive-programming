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

const int MAX = 1050;

struct edge {
    int to, f, c;
};

int s, t, cur, tempo;
int seen[MAX];
edge edges[2*MAX*MAX];
vector<int> adj[MAX], ans[MAX];

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
    edges[cur].to = v, edges[cur].f = 0, edges[cur].c = c;
    adj[u].pb (cur++);
    edges[cur].to = u, edges[cur].f = 0, edges[cur].c = rc;
    adj[v].pb (cur++);
}

int main () {
    int n_k, n_p;
    while (scanf ("%d %d", &n_k, &n_p)) {
        if (n_k == 0 && n_p == 0) break;

        memset (seen, 0, sizeof seen);
        cur = 0, tempo = 1;
        for (int i = 0; i < MAX; i++) 
            adj[i].clear ();
        s = 0;
        t = n_p + n_k + 1;

        int acc = 0;
        for (int i = 1; i <= n_k; i++) {
            int c;
            scanf ("%d", &c);
            acc += c;
            add_edge (n_p + i, t, c, 0);
        }

        for (int i = 1; i <= n_p; i++) {
            int a;
            scanf ("%d", &a);
            while (a--) {
                int v;
                scanf ("%d", &v);
                add_edge (i, n_p + v, 1, 0);
            }
            add_edge (s, i, 1, 0);
        }

        if (ford_fulkerson () == acc) {
            printf ("1\n");
            for (int i = 1; i <= n_p; i++) {
                for (int j = 0; j < adj[i].size (); j++) {
                    if (edges[adj[i][j]].f != 0) {
                        ans[edges[adj[i][j]].to].pb (i);
                    }
                }
            }

            for (int i = n_p + 1; i <= n_p + n_k; i++) {
                printf ("%d", ans[i][0]);
                for (int j = 1; j < ans[i].size (); j++) {
                    printf (" %d", ans[i][j]);
                }
                printf ("\n");
            }
        } else {
            printf ("0\n");
        }
    }
}

