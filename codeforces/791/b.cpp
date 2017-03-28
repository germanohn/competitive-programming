#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 15e4 + 5;

int n, m, cont;
bool seen[N];
vector<int> adj[N];

int dfs(int u) {
    seen[u] = true;
    cont++;
    int q = adj[u].size();
    for (int v : adj[u]) {
        if (!seen[v]) 
            q += dfs(v);
    }
    return q;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bool ok = true;
    for (int i = 0; ok && i < n; i++) {
        if (!seen[i]) {
            cont = 0;
            int q = dfs(i) / 2;
            if (q != ((ll(cont) * ll((cont - 1))) / 2))
                ok = false;
        }
    }

    if (ok) printf("YES\n");
    else printf("NO\n");
}

