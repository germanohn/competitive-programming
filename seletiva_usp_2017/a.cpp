#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e4 + 5;

int n, m, k;
bool seen[N];
int color[N];
vector<int> adj[N];

void dfs(int u, int p) {
    seen[u] = true;

    if (p == -1) color[u] = 0;
    else color[u] = (color[p] + 1) % k;

    for (auto v : adj[u]) {
        if (!seen[v]) 
            dfs(v, u);
    }
}

int main() {
    scanf(" %d %d %d", &n, &m, &k);

    if (k == 1) {
        if (m >= 1) printf("-1\n");
        else {
            for (int i = 0; i < n; i++) 
                printf("1\n");
        }
    } else {
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            a--, b--;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        for (int i = 0; i < n; i++) {
            if (!seen[i]) 
                dfs(i, -1);
        }

        for (int i = 0; i < n; i++) 
            printf("%d\n", color[i] + 1);
    }
}

