#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 405;

int n, m, tempo, raiz;
int low[MAX], d[MAX], ans[MAX];
bool cut[MAX], seen[MAX];
vector<int> adj[MAX];

void dfs (int u, int p) {
    int nf = 0;
    seen[u] = true;
    low[u] = d[u] = tempo++;
    bool any = false;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            nf++;
            dfs (v, u);
            if (low[v] >= d[u])
               any = true;
            low[u] = min (low[u], low[v]); 
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
    if (u == raiz && nf >= 2) 
        cut[u] = true;
    else if (u != raiz && any)
        cut[u] = true;
}

int main () {
    int cont = 1;
    while (scanf ("%d %d", &n, &m) && n != 0) {
        tempo = 0, raiz = 1;
        int a, b;
        for (int i = 0; i < MAX; i++)
            cut[i] = false, seen[i] = false, adj[i].clear (), low[i] = INT_MAX, d[i] = INT_MAX;
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b);
            adj[a].pb (b);
            adj[b].pb (a);
        }
        dfs (1, 0);
        printf ("Teste %d\n", cont++);
        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (cut[i]) 
                ans[k++] = i;
        }
        if (k == 0) printf ("nenhum\n\n");
        else {
            sort (ans, ans+k);
            for (int i = 0; i < k; i++)
                printf ("%d ", ans[i]);
            printf ("\n\n");
        }
    }
}

