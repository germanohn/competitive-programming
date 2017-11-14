#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;

struct tii {
    int hi, vi, loc;
    tii() {}
    tii(int hi, int vi, int loc) : hi(hi), vi(vi), loc(loc) {}
    bool operator< (const tii &x) const {
        return hi < x.hi;
    }
};

int n, m, cont;
int p[N], pre[N], pos[N], lab[N], depth[N], t[4 * N];
bool seen[N];
vector<tii> q;
vector<int> node;
vector<int> adj[N];

void dfs(int u, int d) {
    depth[u] = d++;
    pre[u] = cont++;
    for (int v : adj[u]) 
        dfs(v, d);
    pos[u] = cont - 1;
}

void update(int no, int l, int r, int ind, int val) {
    if (ind < l || ind > r) return;
    if (l == r) {
        t[no] ^= val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * no, l, mid, ind, val);
    update(2 * no + 1, mid + 1, r, ind, val);
    t[no] = t[2 * no] ^ t[2 * no + 1];
}

int query(int no, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return t[no];
    int mid = (l + r) / 2;
    return query(2 * no, l, mid, ql, qr) ^ query(2 * no + 1, mid + 1, r, ql, qr);
}

bool cmp(int a, int b) {
    return depth[a] < depth[b];
}

int main() {
    cont = 0;
    scanf(" %d %d", &n, &m);
    node.pb(0);
    for (int i = 1; i < n; i++) {
        int pi;
        scanf(" %d", &pi);
        pi--;
        adj[pi].pb(i);
        node.pb(i);
    }

    for (int i = 0; i < n; i++) { 
        char c;
        scanf(" %c", &c);
        lab[i] = c - 'a';
    }

    for (int i = 0; i < m; i++) {
        int vi, hi;
        scanf(" %d %d", &vi, &hi);
        vi--;
        q.pb(tii(hi, vi, i));
    }

    sort(q.begin(), q.end());
    dfs(0, 1);
    sort(node.begin(), node.end(), cmp);

    vector<int> ans(m);
    int l = 0, r = 1;
    update(1, 0, n - 1, 0, 1 << lab[node[0]]);
    for (int i = 0; i < m; i++) {
        while (l < n && depth[node[l]] < q[i].hi) {
            update(1, 0, n - 1, pre[node[l]], 1 << lab[node[l]]);
            l++;
        }
        while (r < n && depth[node[r]] <= q[i].hi) {
            update(1, 0, n - 1, pre[node[r]], 1 << lab[node[r]]);
            r++;
        }        

        int bits_on = __builtin_popcount(query(1, 0, n - 1, pre[q[i].vi], pos[q[i].vi]));
        if (bits_on <= 1) {
            ans[q[i].loc] = 1;
        } else {
            ans[q[i].loc] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (ans[i]) printf("Yes\n");
        else printf("No\n");
    }
}

