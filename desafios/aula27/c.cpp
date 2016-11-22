#include<bits/stdc++.h>
#define ff first 
#define ss second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

const int MAX = 505;

int n;
pii me[MAX];
pii seg[MAX];
vector<int> adj[MAX];
vector<int> menor, seq;

int dfs(int u) {
    if (adj[u].size() == 0) {
        me[u].ff = 1, me[u].ss = u;
        return me[u].ff;
    }
    if (me[u].ff != -1) return me[u].ff;

    int cont = 0, ind;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        int val = dfs(v);
        if (val > cont) {
            cont = val;
            ind = v;
        }
    }
    cont++;
    me[u].ff = cont, me[u].ss = ind;

    return me[u].ff;
}

int main() {
    scanf(" %d", &n);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) 
        scanf(" %d %d", &seg[i].ff, &seg[i].ss);

    for (int i = 0; i < n; i++) {
        bool cobre = false;
        for (int j = 0; j < n; j++) {
            if (i == j) 
                continue;
            
            if (seg[i].ff < seg[j].ff && seg[i].ss > seg[j].ss) {
                cobre = true;
                adj[j].pb(i);
            }
        }
        
        if (!cobre) 
            menor.pb(i);
    }

    int ans = 0, ind = 0;
    for (int i = 0; i < menor.size(); i++) {
        int a = menor[i];
        int val = dfs(a);
        if (val > ans) {
            ans = val;
            ind = a;
        }
    }

    printf("%d\n", ans);
    while(me[ind].ss != ind) {
        printf("%d ", ind + 1);
        ind = me[ind].ss;
    }
    printf("%d\n", ind + 1);
}
