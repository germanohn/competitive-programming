#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX 400005
using namespace std;
typedef pair<int, int> pii;

struct celula {
    int esq, dir, mid, best; 
};

celula seg[MAX];

void update (int l, int r, int n, int v, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[n].esq = seg[n].dir = seg[n].mid = seg[n].best = v;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, v, ind);
    update (m+1, r, 2*n+1, v, ind);
    join (n);
}

int join (int n) {
    seg[n].esq = max (seg[2*n].esq, max (seg[2*n].mid + seg[2*n+1].esq, seg[2*n].mid + seg[2*n+1].mid));
    seg[n].dir = max (seg[2*n+1].dir, max (seg[2*n+1].mid + seg[2*n].esq, seg[2*n+1].mid + seg[2*n].mid));
    seg[n].mid = max (seg[2*n]., max (seg[2*n+1].esq, seg[2*n].dir + seg[2*n+1].esq));
}

pii query (int l, int r, int n, int a, int b) {
    ans
    if (a > r || b < l) {
       return INT_MAXi; 
    }
    if (l >= a && r <= b) return seg[n];
    int m = (l+r)/2;
    query (l, m, 2*n, a, b);
    query (m+1, r, 2*n+1, a, b);

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
