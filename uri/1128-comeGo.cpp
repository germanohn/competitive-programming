#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2005;

int n, m, tempo, sn;
int d[MAX], low[MAX], comp[MAX], st[MAX];
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
            comp[a] = u;
            low[a] = INT_MAX;
        } while (a != u);
    }
}

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        tempo = 0, sn = 0;
        int v, w, p;
        for (int i = 1; i <= n; i++) 
            seen[i] = false, adj[i].clear (), comp[i] = 0;
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &v, &w, &p);
            if (p == 1) {
                adj[v].pb (w);
            } else {
                adj[v].pb (w);
                adj[w].pb (v);
            } 
        }
        dfs (1);
        int i;
        for (i = 1; i <= n; i++) {
            if (comp[i] != 1) {
                printf ("0\n");
                break;
            }
        }
        if (i == n+1) 
            printf ("1\n");
    }
}

