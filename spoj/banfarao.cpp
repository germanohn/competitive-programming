#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX 400005
using namespace std;
typedef pair<int, int> pii;

struct tipo {
    int sum1, sum2, ele1, ele2, xx, yy;
};//sum1 é a maior soma de intervalos isolados
//sum2 é a maior soma ate agora do intervalo inteiro

tipo seg[MAX];

void update (int l, int r, int n, int v, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[n].sum1 = seg[n].sum2 = v;
        seg[n].ele1 = seg[n].ele2 = 1;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, v, ind);
    update (m+1, r, 2*n+1, v, ind);
    if (seg[2*n].sum1 > seg[2*n+1].sum1)
        seg[n].sum1 = seg[2*n].sum1, seg[n].ele1 = seg[2*n].ele1;
    if (seg[2*n].sum1 < seg[2*n+1].sum1)
        seg[n].sum1 = seg[2*n+1].sum1, seg[n].ele1 = seg[2*n+1].ele1;
    if (seg[2*n].sum1 == seg[2*n+1].sum1) {
        if (seg[2*n].ele1 > seg[2*n+1].ele1)
            seg[n].sum1 = seg[2*n].sum1, seg[n].ele1 = seg[2*n].ele1;
        else seg[n].sum1 = seg[2*n+1].sum1, seg[n].ele1 = seg[2*n+1].ele1;
    }
    seg[n].sum2 = seg[2*n].sum2 + seg[2*n+1].sum2;
    seg[n].ele2 = seg[2*n].ele2 + seg[2*n+1].ele2;
    if (seg[n].sum2 >= seg[n].sum1)
        seg[n].sum1 = seg[n].sum2, seg[n].ele1 = seg[n].ele2;
}

pii query (int l, int r, int n, int a, int b) {
    tipo ans;
    if (a > r || b < l) {
        ans.sum1 = ans.sum2 = INT_MIN;
        ans.ele1 = ans.ele2 = 0;
        if (a > r) ans.xx = r+1;
        else if (b < l) ans.yy = l-1;
        return ans;
    }
    if (l >= a && r <= b) {
        if (seg[n].sum1 > seg[n].sum2)
            ans.sum1 = seg[n].sum1,      ans.ss = seg[n].ele1;
        else
            ans.ff = seg[n].sum2, ans.ss = seg[n].ele2;
        return ans;
    }
    int m = (l+r)/2;
    pii x = query (l, m, 2*n, a, b), y = query (m+1, r, 2*n+1, a, b);
    if (x.ff > y.ff)
        ans.ff = x.ff, ans.ss = x.ss;
    if (x.ff == y.ff) {
        if (x.ss > y.ss) ans.ff = x.ff, ans.ss = x.ss;
        else ans.ff = y.ff, ans.ss = y.ss;
    }
    if (x.ff < y.ff)
        ans.ff = y.ff, ans.ss = y.ss;
    return ans;
}

int main () {
    int t, conta, aux, q, a, b;
    pii ans;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &conta);
        for (int i = 0; i < conta; i++) {
            scanf ("%d", &aux);
            update (0, conta-1, 1, aux, i);
        }
        scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &a, &b);
            ans = query (0, conta-1, 1, a-1, b-1);
            printf ("%d %d\n", ans.ff, ans.ss);
        }
    }
}
