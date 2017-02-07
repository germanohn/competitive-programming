#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1003;
vector<int> adj[N];
int d[N], memo[N], visi[N];
const int inf = 1123456;

int dp(int u) {
    int &me = memo[u];
    if(visi[u]) return me;
    visi[u] = 1;
    me = 0;
    for(int v : adj[u]) { 
        if(d[v] <= d[u]) continue;
        me |= !dp(v);
    }
    return me;
}

int main () {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 0; i < n; i++) d[i] = inf;
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(d[v] > d[u] + 1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    if(dp(0)) puts("Vladimir");
    else puts("Nikolay");
}

