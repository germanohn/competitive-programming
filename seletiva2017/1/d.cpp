#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 7e4 + 5;
const int inf = 2e9;

int t, n, cont;
int pre[N], pos[N], prof[N], tree[4 * N], ans[N];
pii h[N], d[N];
vector<int> adj[N];

void update(int no, int l, int r, int ind, int val) {
    if (l == r) {
        tree[no] = val;
        return;
    }
    int m = (l + r) / 2;
    if (ind <= m)
        update(2 * no, l, m, ind, val);
    else
        update(2 * no + 1, m + 1, r, ind, val);
    tree[no] = max(tree[2*no], tree[2*no + 1]);
}

int query(int no, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (l >= ql && r <= qr) 
        return tree[no];
    int m = (l + r) / 2;
    return max(query(2 * no, l, m, ql, qr), query(2 * no + 1, m + 1, r, ql, qr));
}

void dfs(int u, int depth) {
    pre[u] = cont++;
    prof[u] = depth;
    for (int v : adj[u]) 
        dfs(v, depth + 1);
    pos[u] = cont - 1;
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        cont = 0;
        for (int i = 0; i < n; i++) 
            adj[i].clear();
        memset(tree, 0, sizeof tree);
        for (int i = 0; i < n; i++) {
            int p;
            scanf(" %d %d %d", &p, &h[i].ff, &d[i].ff);
            h[i].ss = d[i].ss = i;
            if (p == -1) continue;
            adj[p].pb(i);
        }
        dfs(0, 1);
        sort(h, h + n);
        sort(d, d + n);
        int ph, pd;
        ph = pd = 0;
        h[n] = pii(inf, 0), d[n] = pii(inf, 0);
        for (int i = 0; i < 2 * n; i++) {
            if (h[ph].ff <= d[pd].ff) {
                int cur = h[ph].ss;
                update(1, 0, n - 1, pre[cur], prof[cur]);
                ph++;
            } else {
                int cur = d[pd].ss;
                ans[cur] = query(1, 0, n - 1, pre[cur], pos[cur]) - prof[cur];
                pd++;
            }
        }
        for (int i = 0; i < n; i++) 
            printf("%d ", ans[i]);
        printf("\n");
    }
}

