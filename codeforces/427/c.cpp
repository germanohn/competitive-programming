#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int inf = 2e9;
const int MOD = 1e9 + 7;

int n, m, cs, tempo, sz;
int cost[N], low[N], d[N], st[N];
bool seen[N];
vector<int> adj[N], comp[N];

void dfs(int u) {
    seen[u] = true;
    d[u] = low[u] = tempo++;
    st[sz++] = u;
    for (int v : adj[u]) {
        if (!seen[v]) 
            dfs(v);
        low[u] = min(low[u], low[v]);
    }
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            comp[cs].pb(a);
            low[a] = inf;
        } while (a != u);
        cs++;
    }
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &cost[i]);
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
    }

    for (int i = 0; i < n; i++) 
        if (!seen[i])
            dfs(i);

    ll tot = 0, ways = 1;
    for (int i = 0; i < cs; i++) {
        int _min = inf, cont = 0;
        for (int v : comp[i]) {
            if (cost[v] == _min) 
                cont++;
            else if (cost[v] < _min) 
                _min = cost[v], cont = 1;
        }
        tot += _min;
        ways = (ways * cont) % MOD;
    }
    printf("%lld %lld\n", tot, ways);
}

