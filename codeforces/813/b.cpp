#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll x, y, l, r;
vector<ll> v;

int main () {
    scanf(" %lld %lld %lld %lld", &x, &y, &l, &r);

    for (ll i = 1; i <= r; i *= x) {
        for (ll j = 1; j <= r; j *= y) {
            ll cur = i + j;
            if (cur >= l && cur <= r) 
                v.pb(cur);

            if (j > r / y)
                break;
        }

        if (i > r / x) 
            break;
    }

    if (v.size() == 0) {
        printf("%lld\n", r - l + 1);
    } else {
        sort(v.begin(), v.end());
        auto it = unique(v.begin(), v.end());
        v.resize(it - v.begin());

        ll ans = v[0] - l;
        for (int i = 1; i < v.size(); i++) {
            ans = max(ans, v[i] - v[i - 1] - 1);
        }
        ans = max(ans, r - v[v.size() - 1]);

        printf("%lld\n", ans);
    }
}

