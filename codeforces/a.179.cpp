#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const MAX = 100005;

int n, m, k;
ll v[MAX], bitOp[MAX], bitVt[MAX];

struct tipo {
    ll l, r, d;
};

tipo op[MAX];

ll query (ll idx, int tipo) {
    ll sum = 0;
    for (ll i = idx; i > 0; i -= i&-i) {
        if (tipo == 1) sum += bitOp[i];
        else sum += bitVt[i];
    }
    return sum;
}

void update (ll idx, ll val, int tipo) {
    for (ll i = idx; i < MAX; i += i&-i) {
        if (tipo == 1) bitOp[i] += val;
        else bitVt[i] += val;
    }
}

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf ("%I64d", &v[i]);
    }
    ll a, b, c;
    for (int i = 1; i <= m; i++) {
        scanf ("%I64d %I64d %I64d", &a, &b, &c);
        op[i].l = a, op[i].r = b, op[i].d = c;
    }
    ll x, y;
    for (int i = 1; i <= k; i++) {
        scanf ("%I64d%I64d", &x, &y);
        update (x, 1, 1);
        update (y+1, -1, 1);
    }
    for (int i = 1; i <= m; i++) {
        ll quant = query (i, 1);
        update (op[i].l, quant*op[i].d, 0);
        update (op[i].r+1, -quant*op[i].d, 0); 
    }
    for (int i = 1; i <= n; i++) {
        printf ("%I64d ", v[i]+query (i, 0));
    }
    printf ("\n");
}
