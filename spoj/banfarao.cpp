#include <bits/stdc++.h>
#define MAX 100005
#define MIN -10000009
using namespace std;

struct cel {
    int l, r, m, s, ql, qr, qm, qs;
};

cel join (cel a, cel b) {
    cel ans;
    ans.s = a.s + b.s, ans.qs = a.qs + b.qs;
    ans.l = ans.r = ans.m = MIN;
    ans.ql = ans.qr = ans.qm = 0; 
    
    ans.m = max (ans.s, max (b.m, a.m));
    ans.m = max (ans.m, a.r + b.l);
    if (ans.m == ans.s) ans.qm = max (ans.qm, ans.qs);
    if (ans.m == a.m) ans.qm = max (ans.qm, a.qm);
    if (ans.m == b.m) ans.qm = max (ans.qm, b.qm);
    if (ans.m == a.r + b.l) ans.qm = max (ans.qm, a.qr + b.ql); 
    
    ans.r = max (b.r, b.s + a.r);
    if (ans.r == b.r) ans.qr = max (ans.qr, b.qr);
    if (ans.r == b.s + a.r) ans.qr = max (ans.qr, b.qs + a.qr);

    ans.l = max (a.l, a.s + b.l);
    if (ans.l == a.l) ans.ql = max (ans.ql, a.ql);
    if (ans.l == a.s + b.l) ans.ql = max (ans.ql, a.qs + b.ql);

    return ans;
}

cel tree[4*MAX];

cel query (int no, int ini, int fim, int a, int b) {
    if (a > fim || b < ini) {
        cel ans; 
        ans.l = ans.r = ans.m = ans.s = MIN;
        ans.ql = ans.qr = ans.qm = ans.qs = 1;
        return ans;
    }
    if (ini >= a && fim <= b) return tree[no];
    int mid = (ini + fim)/2;
    return join (query (2*no, ini, mid, a, b), query (2*no + 1, mid+1, fim, a, b));
}

void update (int no, int ini, int fim, int v, int ind) {
    if (ind < ini || ind > fim) return;
    if (ini == fim) {
        tree[no].l = tree[no].r = tree[no].m = tree[no].s = v;
        tree[no].ql = tree[no].qr = tree[no].qm = tree[no].qs = 1;
        return;
    }
    int mid = (ini+fim)/2;
    update (2*no, ini, mid, v, ind);
    update (2*no+1, mid+1, fim, v, ind);
    tree[no] = join (tree[2*no], tree[2*no + 1]); 
}

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int N;
        scanf ("%d", &N);
        for (int i = 0; i < N; i++) { 
            int v;
            scanf ("%d", &v);
            update (1, 0, N-1, v, i);
        }
        int Q;
        scanf ("%d", &Q);
        for (int i = 0; i < Q; i++) {
            int a, b;
            scanf ("%d %d", &a, &b);
            cel ans;
            ans = query (1, 0, N-1, a-1, b-1);
            int rta = max (ans.m, max (ans.r, ans.l)), sz = 0;
            if (rta == ans.m) sz = max (sz, ans.qm);
            if (rta == ans.r) sz = max (sz, ans.qr);
            if (rta == ans.l) sz = max (sz, ans.ql);
            printf ("%d %d\n", rta, sz);
        }
    }
}
