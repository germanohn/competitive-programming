#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 105;

int m, n, k, ans;
int color[MAX], opt[MAX];
vector<int> adj[MAX];

void solve (int u, int cont) {
    if (u == n) {
        if (cont > ans) {
            ans = 0;
            for (int i = 0; i < n; i++) 
                if (color[i] == 1) opt[ans++] = i;
        }
        return;
    }
    if (color[u] == -1) solve (u+1, cont);
    else {
        bool black = false;
        for (int v : adj[u]) 
            if (color[v] == 1) black = true;
        if (!black) {
            color[u] = 1;
            for (int v : adj[u])
                color[v] = -1;
            solve (u+1, cont+1);
            color[u] = -1;
            solve (u+1, cont);
        } else {
            color[u] = -1;
            solve (u+1, cont);
        }
    }
    color[u] = 0;
}

void init () {
    for (int i = 0; i < n; i++) 
        adj[i].clear (), color[i] = 0;
    ans = 0;
}

int main () {
    scanf ("%d", &m);
    while (m--) {
        init ();
        scanf ("%d %d", &n, &k);
        for (int i = 0; i < k; i++) {
            int u, v;
            scanf ("%d %d", &u, &v);
            u--, v--;
            adj[u].pb (v);
            adj[v].pb (u);
        }
        solve (0, 0);
        printf ("%d\n", ans);
        for (int i = 0; i < ans-1; i++) 
            printf ("%d ", opt[i]+1);
        printf ("%d\n", opt[ans-1]+1);
    }
}
