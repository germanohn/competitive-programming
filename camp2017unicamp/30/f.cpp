#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 4007;

int n, k;
int m[N], c[N], f[N], sum[N], ans, seen[N];
ll memo2[N][N];
vector<int> e[N];

ll dp2(int i, int k) {
    if(k == 0) return 0;
    if(i == N) return INT_MIN;
    ll &me = memo2[i][k];
    if(me != -1) return me;
    me = 0;
    if(f[i] >= ans) me = max(me, dp2(i+1, k-1) + ll(sum[i]));
    me = max(me, dp2(i+1, k));
    return me;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(memo2, -1, sizeof memo2);
    scanf("%d %d",&n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",m+i, c+i);
        f[m[i]]++;
    }
    vector<int> g;
    for(int i = 0; i < N; i++) if(f[i]) g.pb(f[i]);
    sort(g.begin(), g.end(), greater<int>());
    ans = int(g.size()) >= k ? g[k-1] : 0;
    for(int i = 0; i < n; i++) e[m[i]].pb(c[i]);

    for(int i = 0; i < n; i++) {
        if(seen[m[i]]) continue;
        seen[m[i]] = true;
        sort(e[m[i]].begin(), e[m[i]].end(), greater<int>());
        for(int j = 0; j < min(ans, int(e[m[i]].size())); j++) sum[m[i]] += e[m[i]][j];
    }
    printf("%d %lld\n", ans, dp2(0, k));
}

