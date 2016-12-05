#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n, m, qtd_comp;
int comp[MAX], color_v[MAX], color_c[MAX];
int me[MAX][MAX];
pii qtd_color[MAX];
vector<int> ans1, ans2;
vector<int> adj[MAX];

int dp(int i, int acc) {
    if (i == qtd_comp) return (acc == 0) ? 1 : 0;
    if (acc == 0) {
        bool ok = true;
        for (int j = i; ok && j < qtd_comp; j++) 
            if (qtd_color[j].ff + qtd_color[j].ss > 1) 
                ok = false;
        return (ok == true) ? 1 : 0;
    }
    if (me[i][acc] != -1) return me[i][acc];

    int a = 0, b = 0;
    if (acc - qtd_color[i].ff >= 0)      
        a = dp(i + 1, acc - qtd_color[i].ff);
    if (a == 1) {
        color_c[i] = 0;
        return me[i][acc] = 1;
    }
    if (acc - qtd_color[i].ss >= 0) 
        b = dp(i + 1, acc - qtd_color[i].ss);
    if (b == 1) {
        color_c[i] = 1;
        return me[i][acc] = 1;
    }

    return me[i][acc] = 0;
}

bool dfs(int u, int id) {
    comp[u] = id;
    bool ok = true;
    for (auto v : adj[u]) {
        if (color_v[v] == -1) {
            if (color_v[u] == 0) color_v[v] = 1, qtd_color[id].ss++;
            else color_v[v] = 0, qtd_color[id].ff++;
            ok = dfs(v, id);
        } else if (color_v[v] == color_v[u]) {
            ok = false;
        }
        if (!ok) 
            break;
    }
    return ok;
}

int main() {
    scanf(" %d %d", &n, &m);
    memset(me, -1, sizeof me);
    memset(color_v, -1, sizeof color_v);
    memset(color_c, -1, sizeof color_c);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <= 2*n; i++) {
        if (color_v[i] == -1) {
            color_v[i] = 0;
            qtd_color[qtd_comp].ff++;
            if (!dfs(i, qtd_comp++)) {
                printf("IMPOSSIBLE\n");
                return 0;
            }      
        }
    }   

    if (!dp(0, n)) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    for (int i = 0; i < qtd_comp; i++) {
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
