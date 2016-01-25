#include <bits/stdc++.h>
#define lld I64d
#define MAX 2005
using namespace std;
typedef long long ll;

struct no {
    ll x, y, d;
};

no X[MAX];

ll dist (ll x, ll y, ll a, ll b) {
    return (x-a)*(x-a) + (y-b)*(y-b);
}

bool compare (no a, no b) {
    return a.d < b.d;
}

int main () {
    ll n, x1, y1, x2, y2, a, b;
    scanf ("%I64d %I64d %I64d %I64d %I64d", &n, &x1, &y1, &x2, &y2);
    for (int i = 0; i < n; i++) {
        scanf ("%I64d %I64d", &a, &b);
        X[i].x = a;
        X[i].y = b;
        X[i].d = dist (x1, y1, a, b);
    }
    sort (X, X+n, compare);
    ll ans = LLONG_MAX, tmp;
    for (int i = 0; i < n; i++) {
        ll ma = LLONG_MIN;
        bool f = false;
        tmp = dist (x1, y1, X[i].x, X[i].y);
        for (int j = i+1; j < n; j++) {
            f = true;
            ma = max (ma, dist (x2, y2, X[j].x, X[j].y));
        }
        if (f) ans = min (ans, ma+tmp); 
    }
    tmp = dist (x1, y1, X[n-1].x, X[n-1].y);
    ll aux = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        aux = max (aux, dist (x2, y2, X[i].x, X[i].y));
    }
    tmp = min (tmp, aux);
    ans = min (ans, tmp);
    printf ("%I64d\n", ans);
}
