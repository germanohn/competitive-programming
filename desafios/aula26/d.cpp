#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1123;
const int MOD = 1000003;

struct node {
    int key, l, r, q_l, q_r;
};

int t, n, m, qtd_no;
int me[MAX][MAX];
node tree[4*MAX];

int insert(int no, int val) {
    if (no == -1) {
        tree[qtd_no++].key = val;
        return qtd_no - 1;
    }
    if (val < tree[no].key)
        tree[no].l = insert(tree[no].l, val);
    else 
        tree[no].r = insert(tree[no].r, val);
    return no;
}

int dfs(int no) {
    if (tree[no].key == -1) return 0;
    tree[no].q_l = tree[no].l != -1 ? dfs(tree[no].l) : 0;
    tree[no].q_r = tree[no].r != -1 ? dfs(tree[no].r) : 0;
    return 1 + tree[no].q_l + tree[no].q_r;
}

ll comb(int a, int b) {
    if (b < 0 || a < 0 || a < b) return 0;
    if (a == b || b == 0) return 1;
    if (me[a][b] != -1) return me[a][b];
    return me[a][b] = (comb(a - 1, b - 1) + comb(a - 1, b)) % MOD;
}

ll count_format(int no) {
    if (no == -1) return 1;
    if (tree[no].l == -1 && tree[no].r == -1) return 1;
    //if (tree[no].l == -1) tree[no].q_l = 0;
    //if (tree[no].r == -1) tree[no].q_r = 0;
    return ((((comb(tree[no].q_l + tree[no].q_r, tree[no].q_l) % MOD)
              * count_format(tree[no].l)) % MOD) * count_format(tree[no].r)) % MOD;
}

int main () {
    scanf(" %d", &t);
    memset(me, -1, sizeof me);
    while (t--) {
        qtd_no = 0;
        int raiz = -1;
        scanf(" %d %d", &n, &m);
        memset(tree, -1, sizeof tree);
        for (int i = 0; i < n; i++) {
            int a;
            scanf(" %d", &a);
            raiz = insert(raiz, a);
        }
        dfs(raiz);
        printf("%d\n", (comb(m, n) * count_format(raiz)) % MOD);
    }
}

