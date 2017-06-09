#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

int n, k;
int t[4 * N];
int a[N], v[N];
int sum[N];
int dp[N];

int mod(int x) {
    return ((x % MOD) + MOD) % MOD;
}

void build(int no, int l, int r) {
    if (l == r) {
        t[no] = n;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * no, l, mid);
    build(2 * no + 1, mid + 1, r);

    t[no] = max(t[2 * no], t[2 * no + 1]);
}

void update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        t[no] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * no, l, mid, ind, val);
    update(2 * no + 1, mid + 1, r, ind, val);

    t[no] = max(t[2 * no], t[2 * no + 1]);
}

int query(int no, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[no];
    if (r < ql || l > qr) return 0;

    int mid = (l + r) / 2;
    return max(query(2 * no, l, mid, ql, qr), query(2 * no + 1, mid + 1, r, ql, qr));
}

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    k = min(n, k);
    build(1, 0, k);

    sum[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= k)
            update(1, 0, k, a[i], i);
        int last = query(1, 0, k, 0, k);

        dp[i] = mod(sum[i + 1] - sum[last + 1]);
        sum[i] = (dp[i] + sum[i + 1]) % MOD;
    }

    printf("%d\n", dp[0]);
}

