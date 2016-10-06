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

const int MAX = 705;

struct edge {
    int to, c, f;
};

int cur, tempo;
int seen[MAX];
edge edges[2*MAX*MAX];
vector<int> adj[MAX];

int dfs (int u, int mini) {
    seen[u] = tempo;
    if (u == 'Z') return mini;
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
    while (int up = dfs ('A', INT_MAX)) {
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
    int n;
    scanf ("%d", &n);
    
    cur = 0, tempo = 1;
    while (n--) {
        char u, v;
        int c;
        scanf (" %c %c %d", &u, &v, &c);
        add_edge (u, v, c, c);
    }

    printf ("%d\n", ford_fulkerson ());
}

