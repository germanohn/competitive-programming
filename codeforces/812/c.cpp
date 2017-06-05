#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int N = 1e5 + 5;
const ll inf = 1e17;

ll n, s, k;
ll v[N];
pll aux[N];

bool cmp(pll a, pll b) {
    return a.ff + a.ss * k < b.ff + b.ss * k;
}

ll can() {
    for (int i = 0; i < n; i++) {
        aux[i] = pll(v[i], i + 1);
    }

    //printf("k %lld\n", k);
    sort(aux, aux + n, cmp);
    //for (int i = 0; i < n; i++) 
      //  printf("%lld %lld\n", aux[i].ff, aux[i].ss);

    ll tot = 0;
    for (int i = 0; i < k; i++) {
        tot += (aux[i].ff + aux[i].ss * k);
    }
    //printf("tot %lld\n", tot);

    if (tot <= s) return tot;
    return -1;
}

int main () {
    scanf(" %lld %lld", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i]);
    }

    ll lo = 0, hi = n, cost = inf, q = 0; 
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        k = mid;
        ll tot = can();
        //printf("k %lld tot %lld\n", k, tot);
        if (tot != -1) {
            lo = mid;
            if (q < lo) {
                q = lo;
                cost = tot;
            } else if (q == lo) {
                cost = min(cost, tot);
            }
        } else {
            hi = mid - 1;
        }
    }

    if (cost == inf) cost = 0;
    printf("%lld %lld\n", lo, cost);
}

