#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAX = 200005;

int color[MAX], freq[MAX];
bool seen[MAX];
vector<int> adj[MAX], appear;

int dfs(int u) {
    seen[u] = true;
    freq[color[u]]++;
    appear.pb(u);
    int cont = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!seen[v]) 
            cont += 1 + dfs(v);
    }
    return cont;
}

int main () {
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf(" %d", &color[i]);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int cont = 0, num_comp, ans = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            num_comp = dfs(i) + 1;
            int aux = 0;
            for (int j = cont; j < appear.size(); j++) { 
                aux = max(aux, freq[color[appear[j]]]);
                freq[color[appear[j]]] = 0;
            }
            if (aux != 0) ans += (num_comp - aux);
            cont += num_comp;
        }
    }

    printf("%d\n", ans);
}

