#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;
const int INF = 2e9 + 5;

int n;
int lazy[4 * MAX];
pii t[4 * MAX];
vector<int> ans;
vector<pii> d;

void propagate(int no, int l, int r) {
    t[no].ff += lazy[no];
    if (l != r) 
        lazy[2 * no] += lazy[no], lazy[2 * no + 1] += lazy[no];
    lazy[no] = 0;
}

void update(int no, int l, int r, int ql, int qr, int val) {
    propagate(no, l, r);
    if (ql > r || qr < l) return;
    if (l >= ql && r <= qr) {
        t[no].ff += val;
        if (l != r) 
            lazy[2 * no] += val, lazy[2 * no + 1] += val;
        else 
            t[no].ss = l;
        return;
    }
    int m = (l + r) / 2;
    update(2 * no, l, m, ql, qr, val);
    update(2 * no + 1, m + 1, r, ql, qr, val);
    if (t[2 * no].ff <= t[2 * no + 1].ff) 
        t[no] = t[2 * no];
    else 
        t[no] = t[2 * no + 1];
    if (l == r) t[no].ss = l;
}

pii query(int no, int l, int r, int ql, int qr) {
    propagate(no, l, r);
    if (ql > r || qr < l) return pii(INF, 0);
    if (l >= ql && r <= qr) return t[no]; 
    int m = (l + r) / 2;
    return min(query(2 * no, l, m, ql, qr), query(2 * no + 1, m + 1, r, ql, qr));
}

bool cmp(pii a, pii b) {
    if (a.ff == b.ff) return a.ss > b.ss;
    return a.ff > b.ff;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf(" %d", &n);
    n--;
    int ult;
    for (int i = 0; i < n; i++) {
        int a;
        char c;
        scanf(" %c %d", &c, &a);
        if (c == 'd') { 
            d.pb(pii(a, i));
            update(1, 0, n - 1, i, i, INF);
        } else if (i != n - 1) 
            update(1, 0, n - 1, i, i, a);
        else 
            ult = a;
    }
    sort(d.begin(), d.end(), cmp);
    int gold = 0;
    for (int i = 0; i < d.size(); i++) {
        int d_val, d_pos;
        d_val = d[i].ff, d_pos = d[i].ss;
        pii min_p = query(1, 0, n - 1, d_pos + 1, n - 2);
        if (min_p.ff > 1 || min_p.ss == 0) {
            ans.pb(d_pos + 2), gold += d_val;
            update(1, 0, n - 1, d_pos + 1, n - 2, -1);
        }
    }
    if (query(n) >= ult) {
        printf("%d\n%d\n", gold, ans.size());
        sort(ans.begin(), ans.end());
        for (int a : ans) 
            printf("%d ", a);
        printf("\n");
    } else {
        printf("-1\n");
    }
}

