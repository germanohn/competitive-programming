#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, m;
const ll inf = 2e9 + 5;

bool gap(ll k) {
    if (n + (((k - 1) * (-k)) / 2) <= 0)
        return true;
    return false;
}

int main () {
    scanf(" %lld %lld", &n, &m);

    ll ans = 0;
    if (m >= n) {
        printf("%lld\n", n);
    } else {
        n -= m;
        ll lo = 1, hi = inf; 
        while (lo != hi) {
            ll mid = (lo + hi) / 2;
            if (gap(mid)) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        printf("%lld\n", lo + (m - 1));
    }
}

