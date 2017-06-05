#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e4 + 5;

int n, s;
bool seen[N];
ll level[N], me[N], me2[N];
vector<int> adj[N];

ll dp2(int i) {
    if (i == n - 1) return 1;
    if (me2[i] != -1) return me2[i];

    ll ans = 0;
    for (int u : adj[i])
        ans += dp2(u);
    return me2[i] = ans;
}

ll dp(int i) {
    if (i == n - 1) return 0;
    if (me[i] != -1) return me[i];

    ll ans = 0;
    for (int u : adj[i]) 
        ans = max(ans, me2[u] + dp(u));
    return me[i] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    memset(me2, -1, sizeof me2);
    scanf(" %d %d", &n, &s);
    for (int i = 0; i < s; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
    }
    dp2(0);
    me2[n - 1] = 1;

    printf("%lld\n", me2[0] + dp(0));
}

