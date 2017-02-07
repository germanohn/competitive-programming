#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 31234;

map<int, int> m;
int uf[N], wf[N], n, cs = 1;

int find(int u) {
    if(u == uf[u]) return u;
    return uf[u] = find(uf[u]);
}

bool join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(wf[u] > wf[v]) swap(u,v);
    uf[u] = v;
    wf[v] += wf[u];
    return true;
}

struct edge {
    int u, v, i;
    ll r, p;
    edge () {}
    edge (int i, int u, int v, ll r, ll p) : i(i), u(u), v(v), r(r), p(p) {}
    bool operator<(const edge &o) const {
        if(r != o.r) return r > o.r;
        if(p != o.p) return p > o.p;
        return i < o.i;
    }
} e[N];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b, r, p;
        scanf("%d %d %d %d",&a, &b, &r, &p);
        if(!m[a]) m[a] = cs++;
        if(!m[b]) m[b] = cs++;
        a = m[a];
        b = m[b];
        e[i] = edge(i, a, b, r, p);
    }
    for(int i = 0; i <= cs; i++) {
        uf[i] = i;
        wf[i] = 1;
    }
    ll ans = 0;
    vector<int> res;
    sort(e, e+n);
    for(int i = 0; i < n; i++) {
        int u = e[i].u;
        int v = e[i].v;
        if(join(u,v)) ans += e[i].p;
        res.pb(e[i].i + 1);
    }
    printf("%lld\n", ans);
    reverse(res.begin(), res.end());
    for(int x : res) printf("%d ", x);
    putchar('\n');
}

