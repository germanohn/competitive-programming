#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int M = 20004;
const int N = 1003;

int to[M], head[N], nx[M], es = 1;  
int low[N], d[N], st[N], seen[N], ps, tempo, turn, loc, comp[N], cs;
int n, m, arc[M][2], ans[M];

void dfs(int u) {
    low[u] = d[u] = tempo++;
    st[ps++] = u;
    seen[u] = turn;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(seen[v] != turn) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], low[v]);
    }
    if(d[u] == low[u]) {
        int v;
        int cont = 0;
        do {
            v = st[--ps];
            cont++;
            if(turn == 1) comp[v] = cs;
            low[v] = INT_MAX;
        } while (v != u);
        loc = max(loc, cont);
        cs++;
    }
}

int go(int u){
    tempo = 0; ps = 0;
    turn++;
    loc = 0;
    if(u == -1) {
        for(int u = 0; u < n; u++) if(seen[u] != turn) dfs(u);
    } else dfs(u);
    return loc;
}

int main () {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        to[es] = v; nx[es] = head[u]; head[u] = es++;
        arc[i][0] = u; arc[i][1] = v;
    }
    int first = go(-1);
    int maxi = first;
    for(int i = 0; i < m; i++) {
        int v = arc[i][0], u = arc[i][1];
        ans[i] = first;
        if(comp[u] == comp[v]) continue;
        to[es] = v; nx[es] = head[u]; head[u] = es;
        ans[i] = max(ans[i], go(u));
        maxi = max(maxi, ans[i]);
        head[u] = nx[head[u]];
    }
    printf("%d\n", maxi);
    int cont = 0;
    vector<int> ed;
    for(int i = 0; i < m; i++) if(ans[i] == maxi) ed.pb(i+1);
    printf("%d\n", ed.size());
    for(int v : ed) printf("%d ", v);
    putchar('\n');
}

