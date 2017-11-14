#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
ll pot[N], v[N];

ll mod(ll x) {
    return (x + MOD) % MOD;
}

int main () {
    scanf(" %d", &n);
    ll pot = 1;
    for (int i = 1; i < n; i++) 
        pot = mod(pot * 2);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        scanf(" %lld", &a);
        ans = mod(ans + mod(a * mod(pot - 1)));
    }

    printf("%lld\n", ans);
}

