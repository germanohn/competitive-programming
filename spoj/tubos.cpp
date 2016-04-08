#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, m, tempo;
int d[MAX], low[MAX];
bool seen[MAX], ans;
vector<int> adj[MAX];

void dfs (int u, int p) {
    seen[u] = true;
    d[u] = low[u] = tempo++;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v] > d[u])
                ans = false; 
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
}

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        tempo = 0;
        //memset (pte, 0, sizeof pte);
        for (int i = 0; i <= n; i++) 
            adj[i].clear (), seen[i] = false;
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b);
            adj[a].pb (b);
            adj[b].pb (a);
        }
        ans = true;
        dfs (1, -1);
        if (ans)
            printf ("S\n");
        else 
            printf ("N\n");
    }
}





