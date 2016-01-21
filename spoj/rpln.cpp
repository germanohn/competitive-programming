#include <bits/stdc++.h>
using namespace std;

int seg[400005];

void update (int l, int r, int n, int val, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[n] = val;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, val, ind);
    update (m+1, r, 2*n + 1, val, ind);
    seg[n] = min (seg[2*n], seg[2*n + 1]);
}

int query (int l, int r, int a, int b, int n) {
    if (l >= a && r <= b) return seg[n];
    if (l > b || r < a) return INT_MAX;
    int m = (l+r)/2;
    return min (query (l, m, a, b, 2*n), query (m+1, r, a, b, 2*n + 1));
}

int main () {
    int t, n, q;
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        printf ("Scenario #%d:\n\n", cont++);
        int a, b;
        scanf ("%d %d", &n, &q);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &a);
            update (0, n-1, 1, a, i);
        }
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &a, &b);
            printf ("%d\n", query (0, n-1, a-1, b-1, 1));
        }
    }
}
