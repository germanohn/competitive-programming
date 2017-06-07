#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 5;
const int Q = 2e5 + 5;
const int MAX = 1e6 + 5;

struct tii {
    int l, r, i;
};

int nodes;
tii dq[Q];
int ans[Q];
int t[10 * N];
int lc[10 * N], rc[10 * N];
int root[2 * N];

void build(int no, int l, int r) {
    if (l == r) {
        t[no] = 0;
        return;
    }

    int mid = (l + r) / 2;
    lc[no] = nodes++;
    rc[no] = nodes++;
    build(lc[no], l, mid);
    build(rc[no], mid + 1, r);

    t[no] = t[lc[no]] + t[rc[no]];
}

void update(int cur, int ant, int l, int r, int ind, int val) {
    if (l == r) {
        t[cur] = val;
        return;
    }

    int mid = (l + r) / 2;
    if (ind <= mid) {
        rc[cur] = rc[ant];
        lc[cur] = nodes++;
        update(lc[cur], lc[ant], l, mid, ind, val);
    } else {
        lc[cur] = lc[ant];
        rc[cur] = nodes++;
        update(rc[cur], rc[ant], mid + 1, r, ind, val);
    }

    t[cur] = t[lc[cur]] + t[rc[cur]];
}

int query(int no, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[no];
    if (l > qr || r < ql) return 0;

    int mid = (l + r) / 2;
    return query(lc[no], l, mid, ql, qr) + query(rc[no], mid + 1, r, ql, qr);
}

bool cmp(tii a, tii b) {
    return a.r < b.r;
}

int main () {
    int n;
    scanf(" %d", &n);
    root[n] = nodes++;
    build(0, 0, n - 1);

    int ult[MAX];
    for (int i = 0; i < MAX; i++) 
        ult[i] = -1;

    for (int i = 0; i < n; i++) {
        int val, ant;
        scanf(" %d", &val);
        if (ult[val] != -1) {
            root[n + i + 1] = nodes++;
            update(root[n + i + 1], root[i - 1], 0, n - 1, ult[val], 0);
            ant = root[n + i + 1];
        } else if (i != 0) {
            ant = root[i - 1];
        } else {
            ant = root[n];
        }
        root[i] = nodes++;
        update(root[i], ant, 0, n - 1, i, 1);

        ult[val] = i;
    }

    int q;
    scanf(" %d", &q);
    for (int i = 0; i < q; i++) {
        scanf(" %d %d", &dq[i].l, &dq[i].r);
        dq[i].l--, dq[i].r--;
        dq[i].i = i;
    }

    sort(dq, dq + q, cmp);

    for (int i = 0; i < q; i++) 
        ans[dq[i].i] = query(root[dq[i].r], 0, n - 1, dq[i].l, dq[i].r); 

    for (int i = 0; i < q; i++) 
        printf("%d\n", ans[i]);
}

