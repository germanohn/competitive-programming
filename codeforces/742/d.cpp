#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int inf = -1e9;

int n, m, W, cs;
int w[N], b[N];
int me[N][N];
bool seen[N];
vector<int> color[N], adj[N];

void dfs(int u, int c) {
    seen[u] = true;
    color[c].pb(u);
    for (int v : adj[u]) 
        if (!seen[v])
            dfs(v, c);
}

int dp(int i, int has) {
    if (i == cs + 1) 
        return 0;
    if (me[i][has] != -1) 
        return me[i][has];

    int none, one = 0, all = 0, allB = 0;
    none = dp(i + 1, has);
    for (int x : color[i]) {
        all += w[x];
        allB += b[x];
        if (w[x] <= has)
            one = max(one, b[x] + dp(i + 1, has - w[x]));;
    }
    if (all <= has)
        all = allB + dp(i + 1, has - all);
    else 
        all = 0;

    return me[i][has] = max(none, max(one, all));
}

int main () {
    scanf(" %d %d %d", &n, &m, &W);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &w[i]);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &b[i]);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cs = 1;
    for (int i = 0; i < n; i++) 
        if (!seen[i])
            dfs(i, cs++);

    memset(me, -1, sizeof me);
    printf("%d\n", dp(1, W));
}

