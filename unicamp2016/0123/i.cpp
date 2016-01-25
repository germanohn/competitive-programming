#include <bits/stdc++.h>
#define pb push_back
#define MAX 1000009
using namespace std;

struct tipo {
    int w, x, y;
};

tipo ed[MAX];
bool vis[MAX];
int pai[MAX], sz[MAX];
vector<int> adj[MAX];

void dfs (int node) {
    vis[node] = true;
    for (int i = 0; i < adj[node].size (); i++) {
        int nx = adj[node][i];
        if (!vis[nx]) 
            dfs (nx);
    }
}

int find (int a) {
    if (pai[a] == a) return a;
    return pai[a] = find (pai[a]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap (a, b);
    sz[a] += sz[b], pai[b] = pai[a];
    return true;
}

bool compare (tipo a, tipo b) {
    return a.w < b.w;
}

int main () {
    int n, m;
    while (scanf ("%d %d", &n, &m) && (n != 0 || m != 0)) {
        for (int i = 0; i < n; i++) 
            pai[i] = i, sz[i] = 1, vis[i] = false, adj[i].clear (); 
        for (int i = 0; i < m; i++) 
            scanf ("%d %d %d", &ed[i].x, &ed[i].y, &ed[i].w);
        sort (ed, ed+m, compare);
        int ma = INT_MIN;
        for (int i = 0; i < m; i++) {
            if (join (ed[i].x, ed[i].y)) { 
                adj[ed[i].x].pb (ed[i].y);
                adj[ed[i].y].pb (ed[i].x);
                ma = max (ma, ed[i].w);   
            }         
        }
        dfs (0);
        bool f = true;
        for (int i = 0; i < n && f; i++) {
            if (!vis[i]) {
                printf ("IMPOSSIBLE\n");
                f = false;
            }
        } 
        if (f) printf ("%d\n", ma);
    }
}
