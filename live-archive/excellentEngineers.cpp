#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int inf = 1e9;

struct tii {
    int r1, r2, r3;
};

int test;
int n;
int t[4 * N];
tii r[N];

void update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        t[no] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * no, l, mid, ind, val);
    update(2 * no + 1, mid + 1, r, ind, val);

    t[no] = min(t[2 * no], t[2 * no + 1]);
}

int query(int no, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[no];
    if (l > qr || r < ql) return inf;

    int mid = (l + r) / 2;
    return min(query(2 * no, l, mid, ql, qr), query(2 * no + 1, mid + 1, r, ql, qr));
}

bool cmp(tii a, tii b) {
    return a.r1 < b.r1;
}

int main () {
    scanf(" %d", &test);
    while (test--) {
        scanf(" %d", &n);
        for (int i = 0; i < 4 * n; i++) 
            t[i] = n + 1;
        for (int i = 0; i < n; i++) {
            scanf(" %d %d %d", &r[i].r1, &r[i].r2, &r[i].r3);
        }

        sort(r, r + n, cmp);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int _min = query(1, 0, n - 1, 0, r[i].r3 - 1);
            if (_min > r[i].r2) {
                ans++;
                update(1, 0, n - 1, r[i].r3 - 1, r[i].r2);
            }
        }

        printf("%d\n", ans);
    }
}

