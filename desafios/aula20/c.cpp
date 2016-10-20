#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100005; 

int b, p, l, n;
ll tree[4*MAX];
ll base[MAX];

ll mod(ll x) {
    return x % (ll) p;
}

void update(int no, int l, int r, int ind, ll val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        tree[no] = mod(val);
        return;
    }
    int m = (l + r) / 2;
    if (ind <= m) update(2*no, l, m, ind, val);
    else update(2*no + 1, m + 1, r, ind, val);
    int qtd_dir = r - m;
    tree[no] = mod(mod(base[qtd_dir]*tree[2*no]) + tree[2*no + 1]); 
}

ll query(int no, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (l >= ql && r <= qr) return tree[no];
    int m = (l + r) / 2;
    int qtd_dir;
    qtd_dir = max(0, min(qr - m, r - m));
    return mod(mod(base[qtd_dir]*query(2*no, l, m, ql, qr)) + query(2*no + 1, m + 1, r, ql, qr));
}

main() {
    while(scanf(" %d %d %d %d", &b, &p, &l, &n)) {
        if (b == 0 && p == 0 && l == 0 && n == 0) break;
        base[0] = 1;
        for (int i = 1; i <= l; i++) 
            base[i] = mod(base[i-1]* (ll) b);
        for (int i = 0; i < 4*MAX; i++)
            tree[i] = 0;
        for (int i = 0; i < n; i++) {
            char command;
            int x, y;
            scanf(" %c", &command);
            if (command == 'E') {
                scanf(" %d %d", &x, &y);
                x--;
                update(1, 0, l - 1, x, y);
            } else {
                scanf(" %d %d", &x, &y);
                x--, y--;
                printf("%lld\n", query(1, 0, l - 1, x, y));
            }
        }
        printf("-\n");
    }
}
