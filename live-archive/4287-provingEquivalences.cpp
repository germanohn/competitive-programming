#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;
const int INF = 1000000000;

int t, n, m, sn, tempo, cont;
int in[MAX], out[MAX], comp[MAX];
int d[MAX], low[MAX], st[MAX];
bool seen[MAX];
vector<int> adj[MAX];

void dfs (int u) {
    seen[u] = true;
    st[sn++] = u;
    d[u] = low[u] = tempo++;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v);
            low[u] = min (low[u], low[v]);
        } else {
            low[u] = min (low[u], low[v]);
        }
    }
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sn];
            comp[a] = cont;
            low[a] = INF;
        } while (a != u);
        cont++;
    }
}

int main () {
    int u, v;
    scanf ("%d", &t);
    while (t--) {
        sn = tempo = cont = 0;
        scanf ("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) 
            in[i] = out[i] = 0, adj[i].clear (), seen[i] = false; 
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &u, &v);
            adj[u].pb (v);
        }
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) 
                dfs (i);
        }
        if (cont == 1) {
            printf ("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < adj[i].size (); j++) {
                int k = adj[i][j];
                if (comp[i] != comp[k]) {
                    in[comp[k]]++;
                    out[comp[i]]++;
                }
            }
        }
        int qin = 0, qout = 0;
        for (int i = 0; i < cont; i++) {
            if (in[i] == 0) 
                qin++;
            if (out[i] == 0)
                qout++;
        }
        printf ("%d\n", max (qin, qout));
    }
}
