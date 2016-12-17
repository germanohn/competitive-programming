#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, m, k, turn;
int seen[MAX];
pii gov[MAX];
vector<int> adj[MAX];

pii dfs(int u) {
    seen[u] = turn;
    pii ans = pii(1, adj[u].size());
    for (auto v : adj[u]) {
        if (seen[v] < turn) {
            pii aux = dfs(v);    
            ans.ff += aux.ff, ans.ss += aux.ss;
        }
    }
    return ans;
}

bool cmp(pii a, pii b) {
    return a.ss > b.ss;
}

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int a;
        scanf(" %d", &a); 
        a--;
        gov[a].ff = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    turn = 1;
    int ans = 0;
    for (int i = 0; i < n; i++, turn++) {
        if (seen[i] != 0) continue;
        pii x = dfs(i);
        x.ss /= 2;
        gov[i].ss = x.ff;
        ans += (((x.ff * (x.ff - 1))/2) - x.ss);
    }
    int cont = 0;
    for (int i = 0; i < n; i++) 
        if (gov[i].ff == 0) cont += gov[i].ss;
    int aux = 0;
    for (int i = 0; i < n; i++) {
        if (gov[i].ff == 0) 
            aux += (gov[i].ss * (cont - gov[i].ss));
    }
    ans += (aux/2);
    int mx_node = -1;
    for (int i = 0; i < n; i++) 
        if (gov[i].ff == 1) 
            mx_node = max(mx_node, gov[i].ss);
    ans += (cont * mx_node);
    printf("%d\n", ans);
}

