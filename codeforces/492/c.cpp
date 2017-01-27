#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 100005;

ll n, r, avg;
pll v[MAX];

bool cmp(pll a, pll b) {
    if (a.ss < b.ss) return true;
    return false;
}

int main () {
    scanf(" %lld %lld %lld", &n, &r, &avg);
    ll acc = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %lld %lld", &v[i].ff, &v[i].ss);
        acc += v[i].ff;
    }
    sort(v, v + n, cmp);
    ll p = 0;
    while (acc < avg * n) {
        ll up = min(r - v[p].ff, avg * n - acc);
        acc += up;
        ans += up * v[p++].ss;
    }
    printf("%lld\n", ans);
}

