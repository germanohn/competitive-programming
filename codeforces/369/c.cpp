#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
bool seen[N];
vector<int> ans;
vector<pii> adj[N];

bool dfs(int u) {
    seen[u] = true;
    bool f = false;
    for (pii e : adj[u]) 
        if (!seen[e.ff]) { 
            bool has = dfs(e.ff);
            f |= has;
            if (!has && e.ss == 2) 
                ans.pb(e.ff + 1), f = true;
        }
    return f;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, t;
        scanf(" %d %d %d", &a, &b, &t);
        a--, b--;
        adj[a].pb(pii(b, t));
        adj[b].pb(pii(a, t));
    }

    dfs(0);

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    if (ans.size()) printf("\n");
}

