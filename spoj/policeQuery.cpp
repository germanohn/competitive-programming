#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, e, q, u, v, tempo;
int d[MAX], low[MAX], comp[MAX];
vector<int> adj[MAX];
map<pii, int> bridge;

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
            comp[a] = u;
            low[a] = INT_MAX;
        } while (a != u);
    }
}

void dfs (int u, int p) {
    seen[u] = true;
    int nf = 0;
    d[u] = low[u] = tempo++;
    bool any = false;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v, u);
            nf++;
            low[u] = min (low[u], low[v]);
            if (low[v] >= d[u])
                any = true;
            if (low[v] > d[u]) {
                bridge.insert (pii (v, u));
                bridge.insert (pii (u, v));
            }
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
    if (u == raiz && nf >= 2) 
        cut[u] = true;
    if (u != raiz && any)
        cut[u] = true;
}

int main () {
    scanf ("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf ("%d %d", &u, &v);
        adj[u].pb (v);
        adj[v].pb (u);
    }
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) 
}

