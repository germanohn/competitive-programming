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

int t, n, m, sn, tempo;
int grau[MAX], st[MAX], d[MAX], low[MAX], comp[MAX];
bool seen[MAX];
vector<int> adj[MAX];

void dfsStrong (int u) {
    seen[u] = true;
    st[sn++] = u;
    d[u] = low[u] = tempo++;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfsStrong (v);
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
            low[u] = INT_MAX;
        } while (a != u);
    }
}

void dfs (int u) {
    seen[u] = true;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (comp[u] != comp[v])
            grau[comp[v]]++;
        if (!seen[v]) 
            dfs (v);
    }
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        sn = tempo = 0;
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) 
            adj[i].clear (), seen[i] = false, grau[i] = 0, comp[i] = i;
        int x, y;
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &x, &y);
            adj[x].pb (y);
        }
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                dfsStrong (i);
            }
        }
        for (int i = 1; i <= n; i++)
            seen[i] = false;
        for (int i = 1; i <= n; i++) {
            if (!seen[i])  
                dfs (i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            seen[i] = false;
        for (int i = 1; i <= n; i++) {
            if (!seen[comp[i]] && !grau[comp[i]]) {
                ans++;
                seen[comp[i]] = true;
            }
        }
        printf ("%d\n", ans);
    }
}








