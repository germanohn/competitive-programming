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

int n, m, q, tempo;
int d[MAX], low[MAX];
bool seen[MAX];
vector<int> adj[MAX], pte[MAX];

int dfs (int u, int p) {
    seen[u] = true;
    d[u] = low[u] = tempo++;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v);
            low[u] = min (low[u], low[v]);
            if (low[u] > d[u]) {
                pte[u].pb (v);
                pte[v].pb (u);
            }
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
}

void dfs (int 

int main () {
    int u, v;
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        tempo = 0;
        for (int i = 0; i < n; i++) 
            adj[i].clear (), pte[i].clear (), seen[i] = false;
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &u, &v);
            adj[u].pb (v);
            adj[v].pb (u);
        }
        for (int i = 0; i < n; i++) {
            if (!seen[i]) 
                dfs (i);
        }
        scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &u, &v);
            dfs (u);
        }
    }
}

