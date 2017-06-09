#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pii local[35];
vector<int> adj[35];

void dfs(int u, int p, int dir, int pot) {
    bool vis[4] = {false, false, false, false};
    if (p == -1) 
        local[u] = pii(0, 0);
    else vis[dir] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        int d;
        for (d = 0; d < 4; d++)
           if (!vis[d])
              break;
        vis[d] = true; 

        local[v] = pii(local[u].ff + dx[d] * (1 << pot), local[u].ss + dy[d] * (1 << pot));
        dfs(v, u, d ^ 1, pot - 1); 
    }
}

int main () {
    scanf(" %d", &n);
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        if (adj[u].size() > 4 || adj[v].size() > 4)
            ok = false;
    }
    if (!ok) {
        printf("NO\n");
    } else {
        printf("YES\n");
        dfs(1, -1, 0, 30);
        for (int i = 1; i <= n; i++) 
            printf("%d %d\n", local[i].ff, local[i].ss);
    }
}

