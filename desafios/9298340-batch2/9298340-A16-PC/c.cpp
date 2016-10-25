#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct edge {
    int to, c, f;
};

const int MAX = 200;

int team, prob, s, t, cur, tempo;
int seen[MAX], edge_s[MAX], edge_t[MAX];
edge edges[2*MAX*MAX];
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
    tempo++;
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
    bool f = false;
    while (scanf (" %d %d", &team, &prob)) {
        if (team == 0 && prob == 0) break;

        if (f) printf ("\n");
        f = true;

        s = 0, cur = 0, tempo = 1;
        t = team + prob + 1;
        for (int i = 0; i < MAX; i++) 
            adj[i].clear (), seen[i] = 0;

        for (int i = 0; i < team; i++) {
            int c;
            scanf (" %d", &c);
            edge_s[i+1] = cur;
            add_edge (s, i+1, c, 0); 
            for (int j = 0; j < prob; j++) 
                add_edge (i+1, team+1+j, 1, 0);
        }

        for (int i = 0; i < prob; i++) {
            int c;
            scanf (" %d", &c);
            edge_t[team+1+i] = cur;
            add_edge (team+1+i, t, c, 0); 
        }

        int max_flow = ford_fulkerson ();

        bool ans = true;
        for (int i = 1; ans && i <= team; i++) {
            edge ed = edges[edge_s[i]];
            if (ed.f != ed.c) ans = false;
        }

        for (int i = team+1; ans && i <= team+prob; i++) {
            edge ed = edges[edge_t[i]];
            if (ed.f != ed.c) ans = false;
        }

        if (!ans) {
            printf ("Impossible\n");
        } else {
            for (int i = 1; i <= team; i++) {
                for (int j = 0; j < adj[i].size (); j++) {
                    edge ed = edges[adj[i][j]];
                    //printf ("i %d ed.to %d\n", i, ed.to);
                    if (ed.to == s) continue;
                    if (ed.f == 1) {
                        edges[edge_s[i]].f--;
                        edges[adj[i][j]].c--;
                        edges[adj[i][j] ^ 1].f = 0;
                        edges[edge_t[ed.to]].f--;

                        int aux = ford_fulkerson ();
                        if (aux != 0) {
                            printf ("N");
                        } else {
                            edges[edge_s[i]].f++;
                            edges[adj[i][j]].c++;
                            edges[adj[i][j] ^ 1].f = -1;
                            edges[edge_t[ed.to]].f++;
                            printf ("Y");
                        }
                    } else {
                        printf ("N");
                        edges[adj[i][j]].c--;
                    }
                }
                printf ("\n");
            }
        }
    }    
}

