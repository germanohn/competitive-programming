#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, s;

bool ok(ll val) {
    ll sum = 0;
    ll aux = val;
    while (aux > 0) {
        sum += aux % 10;
        aux /= 10;
    }

    return val >= s + sum;
}

int main () {
    scanf(" %lld %lld", &n, &s);

    if (n <= s) {
        printf("0\n");
    } else {
        ll _max = 18 * 9;
        ll ans = 0;
        if (s + _max < n) {
            ans += (n - (s + _max));
        }

        for (ll i = s; i <= min(s + _max, n); i++) {
            if (ok(i)) {
                ans++;
            }
        }

        printf("%lld\n", ans);
    }
}

