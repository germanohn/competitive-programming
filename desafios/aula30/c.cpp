#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n, m, qtd_comp;
int color_v[MAX], comp[MAX], color_c[MAX];
int me[MAX];
pii qtd_c[MAX];
vector<int> adj[MAX];

int dp(int i, int acc) {
    if (i == qtd_comp) return acc == 0 : 1 ? 0;
    if (acc == 0) return 1;
    if (me[i][acc] != -1) return me[i][acc];

    int a, b;
    if (acc - qtd_c[i].ff >= 0)      
        a = dp(i + 1, acc - qtd_c[i].ff);
    if (a == 1) {
        color_c[i] = 0;
        return me[i][acc] = 1;
    }
    if (acc - qtd_c[i].ss >= 0) 
        b = dp(i + 1, acc - qtd_c[i].ss);
    if (b == 1) {
        color_c[i] = 1;
        return me[i][acc] = 1;
    }

    return me[i][acc] = 0;
}

void dfs(int u, int id) {
    comp[u] = id;
    for (auto v : adj[u]) {
        if (color_v[v] == -1) {
            if (color_v[u] == 0) color_v[v] = 1, qtd_c[id].ss++;
            else color_v[v] = 0, qtd_c[id].ff++;
            dfs(v);
        }
    }
}

int main() {
    scanf(" %d %d", &n, &m);
    memset(me, -1, sizeof me);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int qtd_comp = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (color_v[i] == -1) {
            color_v[i] = 0;
            qtd_c[qtd_comp].ff++;
            dfs(i, qtd_comp++);        
        }
    }   

    for (int i = 0; i < qtd_comp; i++) {
        int col = color_c[i]
        for (int j = 1; j <= 2*n; j++) {
            if (comp[j] == i) {
                if (color_v[j] == color_c[i]) ans1.pb(j);
                else ans2.pb(j);
            }
        }
    }

    for (int i = 0; i < ans1.size(); i++) 
        printf("%d ", ans1[i]);
    printf("\n");
    for (int i = 0; i < ans2.size(); i++) 
        printf("%d ", ans2[i]);
    printf("\n");
    
}
