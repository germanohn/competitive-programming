#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1000000009;
const int MAX = 500005;

struct no {
    int l, r, best, sum;

    no(int l, int r, int best, int sum) : l(l), r(r), best(best), sum(sum) {}
    no() : l(0), r(0), best(0), sum(0) {}

    no operator + (no x) {
        int ans_l, ans_r, ans_best, ans_sum;
        ans_l = max(l, sum + x.l);
        ans_r = max(x.r, x.sum + r);
        ans_sum = sum + x.sum;
        ans_best = max(best, max(x.best, r + x.l));
        return no(ans_l, ans_r, ans_best, ans_sum);
    }
};

int n;
no tree[4*MAX];

void update(int node, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        tree[node] = no(val, val, val, val);    
        return;
    }
    int m = (l + r) / 2;
    if (ind <= m) update(2*node, l, m, ind, val);
    else update(2*node + 1, m + 1, r, ind, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

no query(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return no(-inf, -inf, -inf, 0);
    if (l >= ql && r <= qr) return tree[node];
    int m = (l + r) / 2;
    return query(2*node, l, m, ql, qr) + query(2*node + 1, m + 1, r, ql, qr);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        update(1, 0, n - 1, i, a);
    }
    int q;
    scanf(" %d", &q);
    while (q--) {
        int command, x, y;
        scanf(" %d %d %d", &command, &x, &y);
        if (command == 1) {
            no ans = query(1, 0, n - 1, x - 1, y - 1);
            printf("%d\n", ans.best);
        } else 
            update(1, 0, n - 1, x - 1, y);
    }
}
