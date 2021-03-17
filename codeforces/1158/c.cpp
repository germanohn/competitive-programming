#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 5 * 1e5 + 5;

int n;
int tree[4 * N], next[N], p[N];

void update(int no, int l, int r, int idx, int val) {
    if (l == r) {
        t[no] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) 
        update(2 * no, l, mid, idx, val);
    if (idx > mid) 
        update(2 * no + 1, mid + 1, r, idx, val);
    tree[no] = find_max(tree[2 * no], tree[2 * no + 1]);
}

int find_max(int l, int r) {
    if (next[l] != -1 && next[r] != -1) {
        if (next[l] < next[r])
            return r;
        return l;
    } else if (next[l] == -1 && next[r] != -1) {
        return -1;
    } else if (next[l] != -1 && next[r] == -1) {
        if (next[l] < r) 
            return r;
        return l;
    } 
    return l;
}

int query(int no, int l, int r, int ql, int qr) {
    if (ql >= l && qr <= r) 
        return tree[no];
    if (ql > r || qr < l) 
        return n + 1;
    int mid = (l + r) / 2;
    int a = query(2 * no, l, r, ql, mid);
    int b = query(2 * no + 1, l, r, mid + 1, qr);

    return find_max(a, b); 
}

void set_permutation(int l, int r, int a, int b) {
    int count = b - a + 1;
    int _max = query(1, 0, n - 1, l, r);
    p[_max] = b;

    if (_max > l) 
        set_permutation(l, _max - 1, a, a + _max - 1);
    if (_max < r) 
        set_permutation(_max + 1, r, a + 
}

int main() {
    int t;
    scanf(" %d", &t);

    while (t--) {
        scanf(" %d", &n);
        memset(tree, 0, 4 * n);
        for (int i = 0; i < n; i++) {
           scanf(" %d", &next[i]);
           update(1, 0, n - 1, i, next[i]);
        }
        next[n + 1] = 0; 

        set_permutation(1, n, 1, n);
        if (permutation_is_valid()) {
            printf("-1\n");
        } else {
            for (int i = 0; i < n; i++) 
                printf("%d ", p[i]);
            printf("\n");
        }
    }
}

