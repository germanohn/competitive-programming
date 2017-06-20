#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 5;
const ll MOD = 1e9 + 7;

int n;
ll x[N];
ll pot[N];
ll pre[N], suf[N];

ll mod(ll x) {
    return (x + MOD) % MOD;
}

ll calc(int k) {
    if (n <= k + 1) return 0;
    int left = min(n - (k + 1), k + 1);
    return mod(pot[k] * mod(suf[n - left + 1] - pre[left]));
}

int main () {
    scanf(" %d", &n);

    pot[0] = 1;
    for (int i = 1; i < n; i++) {
        pot[i] = mod(pot[i - 1] * 2);
    }

    for (int i = 0; i < n; i++) {
        scanf(" %lld", &x[i]);
    }
    sort(x, x + n);

    for (int i = 1; i <= n; i++) {
        pre[i] = mod(x[i - 1] + pre[i - 1]);
    }

    for (int i = n; i >= 1; i--) {
        suf[i] = mod(x[i - 1] + suf[i + 1]);
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = mod(ans + calc(i));
    }

    printf("%lld\n", ans);
}



