#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, f;
pii p[N];

bool cmp(pii a, pii b) {
    int plusA = min(max(0, a.ss - a.ff), a.ff);
    int plusB = min(max(0, b.ss - b.ff), b.ff);

    return plusA > plusB;
}

int main () {
    scanf(" %d %d", &n, &f);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &p[i].ff, &p[i].ss);
    }

    sort(p, p + n, cmp);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 <= f) {
            ans += ll(min(max(0, p[i].ss - p[i].ff), p[i].ff));
        }
        ans += ll(min(p[i].ff, p[i].ss));
    }

    printf("%lld\n", ans);
}

