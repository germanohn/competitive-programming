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

struct edge {
    int to, c, f;
};

int cur, tempo, s, t;
int seen[MAX];
edge edges[2*MAX*MAX];
vector<int> adj[MAX];

int dfs (int u, int mini) {
    seen[u] = tempo;
    if (u == t) return mini;
    for (int i = 0; i < adj[u].size (); i++) {
        edge ed = edges[adj[u][i]];
        if (seen[ed.to] != tempo && ed.c - ed.f > 0) {
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
    int n, c, cont = 1;
    while (scanf ("%d", &n) && n != 0) {
        scanf ("%d %d %d", &s, &t, &c); s--; t--;

        cur = 0, tempo = 1;
        memset (seen, 0, sizeof seen);
        for (int i = 0; i < MAX; i++) 
            adj[i].clear ();

        for (int i = 0; i < c; i++) {
            int u, v, cp;
            scanf (" %d %d %d", &u, &v, &cp);
            u--, v--;
            add_edge (u, v, cp, cp); 
        }

        printf ("Network %d\n", cont++);
        printf ("The bandwidth is %d.\n\n", ford_fulkerson ());
    }
}

