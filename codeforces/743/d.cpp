#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 200005;
const ll inf = 3e15;

int n;
ll acc[MAX];
bool seen[MAX];
vector<int> adj[MAX];

ll dfs(int u) {
    seen[u] = true;
    for (auto v : adj[u]) 
        if (!seen[v]) 
            acc[u] += dfs(v);
    return acc[u];
}

/* first: melhor soma de um pair nas subarvores de u, se nao tiver 
 * um pair tera -1. 
 * second: melhor subarvore de u pra juntar com outra subarvore de u */
pll solve(int u) {
    seen[u] = true;
    pll ans = pll(-inf, acc[u]);
    ll a, b;
    a = b = -inf;
    for (auto v : adj[u]) {
        if (seen[v]) continue;
        pll son = solve(v);
        ans.ff = max(ans.ff, son.ff);       
        ans.ss = max(ans.ss, son.ss);
        if (son.ss > a) b = a, a = son.ss;
        else if (son.ss > b) b = son.ss;
    }
    if (a != -inf && b != -inf) 
        ans.ff = max(ans.ff, a + b);
    return ans;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %lld", &acc[i]);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    for (int i = 0; i < n; i++) seen[i] = false;
    pll ans = solve(0);
    if (ans.ff == -inf) 
        printf("Impossible\n");
    else 
        printf("%lld\n", ans.ff);
}

