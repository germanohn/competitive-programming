#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int a, b, n;
ll fat[N];

ll fexp(ll x, int e) {
    if (e == 0) return 1;
    if (e == 1) return x;
    if (e % 2 == 0) return (fexp((x * x) % MOD, e / 2)) % MOD;
    return (x * fexp((x * x) % MOD, e / 2)) % MOD;
}

ll inv(ll x) {
    return fexp(x, MOD - 2);
}

ll comb(ll x, ll y) {
    return (fat[x] * inv((fat[y] * fat[x - y]) % MOD)) % MOD;
}

int main () {
    scanf(" %d %d %d", &a, &b, &n);

    fat[0] = 1;
    for (int i = 1; i < N; i++) 
        fat[i] = (i * fat[i - 1]) % MOD;

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        int x = i * a + (n - i) * b;
        bool good = true;
        while (x > 0 && good) {
            int dig = x % 10;
            x /= 10;
            if (dig != a && dig != b) 
                good = false;
        }
        if (good) 
            ans = (ans + comb(n, i)) % MOD;
    }
    
    printf("%lld\n", ans);
}

