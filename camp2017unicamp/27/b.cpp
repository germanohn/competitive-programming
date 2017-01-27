#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 112345;

int n, g;
vector<int> adj[MAXN];
bool seen[MAXN], color[MAXN];

void dfs(int u, bool c) {
    color[u] = c;
    seen[u] = true;
    for (int v : adj[u])
        if (!seen[v]) 
            dfs(v, !c);
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf(" %d %d", &n, &g);
    g--;
    for (int i = 0; i < n; i++) {
        int gi, v;
        scanf(" %d", &gi);
        while (gi--) {
            scanf(" %d", &v);
            v--;
            adj[i].pb(v);
        }
    }
    dfs(g, true);
    for (int i = 0; i < n; i++) {
        if (!seen[i] && (int) adj[i].size() <= 1) puts("-");
        else if ((int) adj[i].size() <= 1)
            printf("%s\n", color[i] ? "CW" : "CCW");
    }
}

