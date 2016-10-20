#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100005;

int tree[4*MAX];

void update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) 
        return;
    if (l == r) {
        tree[no] = val;
        return;
    }
    int m = (l + r) / 2;
    update(2*no, l, m, ind, val);
    update(2*no + 1, m + 1, r, ind, val);
    tree[no] = min(tree[2*no], tree[2*no + 1]);
}

int query(int no, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return INT_MAX;
    if (l >= ql && r <= qr) return tree[no];
    int m = (l + r) / 2;
    return min(query(2*no, l, m, ql, qr), query(2*no + 1, m + 1, r, ql, qr));
}

int main() {
    int t, cont = 1, n, q;
    scanf("%d", &t);
    while (t--) {
        scanf(" %d %d", &n, &q);
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            update(1, 0, n - 1, i, val);
        }

        printf("Scenario #%d:\n", cont++);
        for (int i = 0; i < q; i++) {
            int ql, qr;
            scanf("%d %d", &ql, &qr);
            ql--, qr--;
            printf("%d\n", query(1, 0, n - 1, ql, qr)); 
        }
    }
}
