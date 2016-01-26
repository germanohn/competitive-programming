#include <bits/stdc++.h>
#define MAX 400100
using namespace std;
typedef long long ll;

ll seg[MAX];
ll lazy[MAX];
int n;

void propagate (int l, int r, int no) {
    seg[no] += (lazy[no] * ((ll) (r-l+1)));
    if (l != r) {
        lazy[2*no] += lazy[no];
        lazy[2*no+1] += lazy[no];
    }
    lazy[no] = 0;
}

void update (int l, int r, int no, int a, int b, ll v) {
    propagate (l, r, no);
    if (b < l || a > r) return;
    if (l >= a && r <= b) {
        seg[no] += (v * ((ll) (r-l+1)));
        if (l != r) {
            lazy[2*no] += v;
            lazy[2*no+1] += v;
        }
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*no, a, b, v);
    update (m+1, r, 2*no+1, a, b, v);
    if (l != r)
        seg[no] = seg[2*no]+seg[2*no+1];
}

void update (int a, int b, ll v) {
    update (0, n-1, 1, a, b, v);
}

ll query (int l, int r, int no, int a, int b) {
    propagate(l, r, no);
    if (a > r || b < l) return 0;
    if (l >= a && r <= b) return seg[no];
    int m = (l+r)/2;
    return query (l, m, 2*no, a, b) + query (m+1, r, 2*no+1, a, b);
}

ll query (int a, int b) {
    return query (0, n-1, 1, a, b);
}

int main () {
    int t, c, a, b;
    ll v;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &c);
        memset (seg, 0, sizeof seg);
        memset (lazy, 0, sizeof lazy);
        for (int i = 0; i < c; i++) {
            scanf ("%d", &a);
            if (a == 0) {
                scanf ("%d %d %lld", &a, &b, &v);
                update (a-1, b-1, v);
            }
            else {
                scanf ("%d %d", &a, &b);
                printf ("%lld\n", query (a-1, b-1));
            }
        }
    }
}
