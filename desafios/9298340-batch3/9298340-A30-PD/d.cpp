#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

struct triple {
    int d, r, p_c;
};

int n, m;
int ans[MAX];
ll bit_t[MAX], bit_d[MAX];
pii wd[MAX];
triple c[MAX];

void update(int idx, ll val, int kind) {
    for (int i = idx; i < MAX; i += i & -i) {
        if (kind) bit_t[i] += val;
        else bit_d[i] += val;
    }
}

ll query(int idx, int kind) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= i & -i) {
        if (kind) sum += bit_t[i];
        else sum += bit_d[i];
    }
    return sum;
}

bool cmp_wd(pii a, pii b) { return a.ff > b.ff; }

bool cmp_c(triple a, triple b) { return a.d > b.d; }

int main () {
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf(" %d", &wd[i].ff);
        wd[i].ss = i + 1;
    }

    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &c[i].d, &c[i].r);
        c[i].p_c = i;
    }

    sort(wd, wd + m, cmp_wd);
    sort(c, c + n, cmp_c);

    int p_wd = 0;
    for (int i = 0; i < n; i++) {
        while (wd[p_wd].ff > c[i].d && p_wd < m) {
            update(wd[p_wd].ss, wd[p_wd].ff, 1);
            update(wd[p_wd].ss, 1, 0);
            p_wd++;
        }
        int lo, hi;
        lo = 1, hi = m + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (c[i].d * query(mid, 0) + c[i].r <= query(mid, 1)) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        ans[c[i].p_c] = (lo != m + 1) ? lo : 0;
    }

    for (int i = 0; i < n; i++) 
        printf("%d ", ans[i]);
    printf("\n");
}

