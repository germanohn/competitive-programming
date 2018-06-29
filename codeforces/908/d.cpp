// Implementação inspirada em código de gabrielrc
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e3 + 5;

ll fexp(ll b, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e % 2 == 1) 
            ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return ans;
}

ll inv(ll a) {
    return fexp(a, MOD - 2);
}

struct mod {
    ll x;
    mod() {}
    mod(ll _x) : x(_x) {}

    mod operator+ (const mod &a) {
        return mod((x + a.x + MOD) % MOD);
    }
    mod operator- (const mod &a) {
        return mod((x - a.x + MOD) % MOD);
    }
    mod operator* (const mod &a) {
        return mod((x * a.x) % MOD);
    }
    mod operator/ (const mod &a) {
        return mod(x) * mod(inv(a.x));
    }
};

int k, pa, pb;
mod p;
mod me[N][N];
bool vis[N][N];

mod dp(int a, int ab) {
    if (a + ab >= k) return ((mod(1) - p) / p) + mod(a);
    if (vis[a][ab]) return me[a][ab];
    vis[a][ab] = true;
    return me[a][ab] = ((mod(1) - p) * dp(a + 1, ab)) + (p * (dp(a, a + ab) + a));
}

int main() {
    scanf(" %d %d %d", &k, &pa, &pb);
    p = mod(pb) / mod(pa + pb);
    printf("%lld\n", (mod(1) / (mod(1) - p) * dp(0, 0)).x);
}

