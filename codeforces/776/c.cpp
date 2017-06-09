#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const ll inf = 1e14 + 5;

int n;
ll k;
ll acc[N];
map<ll, vector<int> > mp;

ll calc(ll pot) {
    ll qtd = 0;
    for (int i = 1; i <= n; i++) {
        ll want = acc[i] - pot, aux;
        if (mp[want].size() != 0) {
            aux = lower_bound(mp[want].begin(), mp[want].end(), i) - mp[want].begin();
            qtd += aux;
        }
    }
    return qtd;
}

int main () {
    scanf(" %d %lld", &n, &k);
    scanf(" %lld", &acc[1]);
    mp[0].pb(0);
    mp[acc[1]].pb(1);
    for (int i = 1; i < n; i++) {
        scanf(" %lld", &acc[i + 1]);
        acc[i + 1] += acc[i];
        mp[acc[i + 1]].pb(i + 1);
    }

    ll ans = 0;
    if (k == 1) {
        ans = calc(1);
    } else if (k == -1) {
        ans = calc(1) + calc(-1);
    } else {
        ans += calc(1);
        ll pot = k;
        while (abs(k) < inf) {
            ans += calc(k);
            k *= pot;
        }
    }
    printf("%lld\n", ans);
}

