#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll B, G;
ll me[1005][1005];

ll dp (ll b, ll g) {
    if (b == 0) return g == 0;
    if (me[b][g] != -1) return me[b][g];
    ll ans = 0;
    ans += (dp (b-1, g-1) * g) % MOD;
    ans += (dp (b-1, g) * (G-g)) % MOD;
    return me[b][g] = ans;
}

int main () {
    while (scanf ("%lld %lld", &B, &G) && B != 0 && G != 0) {
        memset (me, -1, sizeof me);
        printf ("%lld\n", dp (B, G));
    }
}
