#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n, root;
int t[MAX], acc[MAX], p[MAX];
vector<int> ans;
vector<int> adj[MAX];

int dfs(int u) {
    acc[u] = t[u];
    for (int v : adj[u]) 
        acc[u] += dfs(v);
    return acc[u];
}

void dfs2(int u) {
    for (int v : adj[u]) {
        if (acc[v] == acc[root] / 3) 
            ans.pb(v);
        else if (acc[v] == 2 * acc[root] / 3)
            ans.pb(v); dfs2(v);
    }
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &p[i], &t[i]);
        p[i]--;
        if (p[i] != -1) {
            adj[p[i]].pb(i);
        } else 
            root = i;
    }
    dfs(root);
    if (acc[root] % 3 == 0) 
        dfs2(root);
    if (ans.size() < 2) 
        printf("-1\n");
    else 
        printf("%d %d\n", ans[0] + 1, ans[1] + 1);
}
