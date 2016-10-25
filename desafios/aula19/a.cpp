#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 200005;

int tree[4*MAX];

void update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        tree[no] = val;
        return;
    }

    int m = (l + r) / 2;
    update(2*no, l, m, ind, val);
    update(2*no + 1, m + 1, r, ind, val);
    tree[no] = tree[2*no] + tree[2*no + 1];
}

int query(int no, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return tree[no];
    if (qr < l || ql > r) return 0;
    int m = (l + r) / 2;
    return query(2*no, l, m, ql, qr) + query(2*no + 1, m + 1, r, ql, qr);
}

int main () {
    int n, cont = 1;
    bool f = false;
    while (scanf(" %d", &n) && n != 0) {
        if (f) printf("\n");
        f = true;
        char s[10];
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            update(1, 0, n - 1, i, val); 
        }
        printf("Case %d:\n", cont++);
        while(scanf("%s", s)) {
            int x, y;
            if (strcmp(s, "END") == 0) 
                break;
            scanf("%d %d", &x, &y);
            if (s[0] == 'S') {
                update(1, 0, n - 1, x - 1, y);
            } else if (s[0] == 'M') {
                printf("%d\n", query(1, 0, n - 1, x - 1, y - 1));
            }
        }
    }
}

