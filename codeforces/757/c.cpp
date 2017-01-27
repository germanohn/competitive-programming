#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXM = 1000005;
const int MOD = 1e9 + 7;

int n, m;
ll me[MAXM];
map<vector<int>, int> poke;
vector<int> v[MAXM];

ll factorial(ll x) {
    if (x == 0) return 1;
    if (me[x] != -1) return me[x];
    return me[x] = (x * factorial(x - 1)) % MOD;
}

int main () {
    scanf(" %d %d", &n, &m);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        int g;
        scanf(" %d", &g);
        while (g--) {
            int a;
            scanf(" %d", &a);
            v[a].pb(i);
        }
    }
    ll not_appear = 0;
    for (int i = 1; i <= m; i++) {
        if (v[i].size() != 0) { 
            poke[v[i]]++; 
        } else 
            not_appear++;
    }
    ll ans = 1;
    for (auto it = poke.begin(); it != poke.end(); it++) 
        ans = (ans * factorial(it->ss)) % MOD;
    ans = (ans * factorial(not_appear)) % MOD;
    printf("%lld\n", ans);
}

