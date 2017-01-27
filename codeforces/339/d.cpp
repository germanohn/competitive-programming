#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m;
int tree[4 * MAX];

int update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return 0;
    if (l == r) {
        tree[no] = val;
        return 1;
    }
    int m = (l + r) / 2, dis;
    if (ind <= m) dis = update(2 * no, l, m, ind, val);
    else dis = update(2 * no + 1, m + 1, r, ind, val);
    if (dis % 2 == 1) tree[no] = tree[2 * no] | tree[2 * no + 1];
    else tree[no] = tree[2 * no] ^ tree[2 * no + 1];
    return dis + 1;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < (1 << n); i++) {
        int a;
        scanf(" %d", &a);
        update(1, 0, (1 << n) - 1, i, a);
    }
    for (int i = 0; i < m; i++) {
        int p, b;
        scanf(" %d %d", &p, &b);
        update(1, 0, (1 << n) - 1, p - 1, b);
        printf("%d\n", tree[1]);
    }
}

