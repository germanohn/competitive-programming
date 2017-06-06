#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, x;
int d[N][2];
bool seen[N];
vector<int> adj[N];

void dfs(int u, int k) {
    seen[u] = true;
    for (auto v : adj[u]) {
        if (!seen[v]) {
            d[v][k] = d[u][k] + 1;
            dfs(v, k);
        }
    }
}

int main () {
    scanf(" %d %d", &n, &x);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);
    for (int i = 0; i < n; i++)
        seen[i] = 0;
    dfs(x - 1, 1);

    int ans = 0;
    for (int i = 0; i < n; i++) 
        if (d[i][0] > d[i][1]) 
            ans = max(ans, d[i][0]);

    printf("%d\n", 2 * ans);
}

