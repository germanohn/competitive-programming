#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define rank huaeshuse
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 412345;

vector<ll> tree[N][3];
vector<int> adj[N];
int tempo = 0, pre[N], pos[N], e, m[N], rank[N], plan[N];
ll t[N];

void dfs(int u, int p) {
    pre[u] = tempo;
    plan[tempo++] = u;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u);
    pos[u] = tempo;
}

vector<ll> merge(vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<ll> &d, vector<ll> &vert){
    vector<ll> ret;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ret.pb(a[i]);
            vert.pb(c[i++]);
        }
        else { 
            ret.pb(b[j]);
            vert.pb(d[j++]);
        }
    }
    while(i < a.size()) ret.pb(a[i]), vert.pb(c[i++]);
    while(j < b.size()) ret.pb(b[j]), vert.pb(d[j++]);
    return ret;
}

vector<ll> merge_acc(vector<ll> &v) {
    vector<ll> ret;
    ret.pb(t[v[0]]);
    for(int i = 1; i < v.size(); i++)
        ret.pb(*ret.rbegin() + t[v[i]]);
    return ret;
}

void build(int k = 1, int l = 0, int r = e-1) {
    if(l == r) {
        tree[k][0].pb(rank[plan[l]]);
        tree[k][1].pb(t[plan[l]]);
        tree[k][2].pb(plan[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*k, l, mid);
    build(2*k+1, mid+1, r);
    tree[k][0] = merge(tree[2*k][0], tree[2*k+1][0], tree[2*k][2], tree[2*k+1][2], tree[k][2]);
    tree[k][1] = merge_acc(tree[k][2]);
}

ll query(int fl, int fr, int rk, int k = 1, int l = 0, int r = e-1) {
    if(fl > fr) return 0;
    if(l > fr || r < fl) return 0;
    if(l >= fl && r <= fr) {
        int i = lower_bound(tree[k][0].begin(), tree[k][0].end(), rk) - tree[k][0].begin() - 1;
        if(i < 0) return 0;
        return tree[k][1][i];
    }
    int mid = (l+r)/2;
    return query(fl, fr, rk, 2*k, l, mid) + query(fl, fr, rk, 2*k+1, mid+1, r);
}

int main () {
    scanf("%d",&e);
    int root;
    for(int i = 0; i < e; i++) {
        scanf("%d %d %lld", m+i, rank+i, t+i);
        if(m[i] > 0) m[i]--;
        if(m[i] < 0) root = i;
    }

    for(int i = 0; i < e; i++) {
        if(m[i] >= 0){ 
            adj[m[i]].pb(i);
        }
    }

    dfs(root, -1);
    build();
    
    for(int i = 0; i < e; i++)
        printf("%lld\n", query(pre[i]+1, pos[i]-1, rank[i]));
   
    
}

