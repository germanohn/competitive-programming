#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int tree[4*MAX];

void update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        if (val > 0) tree[no] = 1;
        else if (val < 0) tree[no] = -1;
        else tree[no] = 0;
        return;
    }
    int m = (l + r) / 2;
    update(2*no, l, m, ind, val);
    update(2*no + 1, m + 1, r, ind, val);
    tree[no] = tree[2*no] * tree[2*no + 1];
}

int query(int no, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 1;
    if (l >= ql && r <= qr) return tree[no];
    int m = (l + r) / 2;
    return query(2*no, l, m, ql, qr) * query(2*no + 1, m + 1, r, ql, qr);
}

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            update(1, 0, n - 1, i, val);
        }

        for (int i = 0; i < k; i++) {
            char command;
            int a, b;
            scanf(" %c %d %d", &command, &a, &b);
            if (command == 'C') {
                a--;
                update(1, 0, n - 1, a, b);
            } else {
                a--, b--;
                int ans = query(1, 0, n - 1, a, b);
                if (ans == 0) printf("0");
                else if (ans < 0) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
    
}
