#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int time;

void dfs (int u, int p) {
    seen[u] = true;
    nf = 0;
    low[u] = d[u] = time++;
    bool any = false;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            nf++;
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v] >= d[u]) 
                any = true;
            if (low[v] > d[u]) 
                uv é ponte;
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
    if (u == raiz && nf >= 2) 
        u é de corte;
    else if (u != raiz && any) 
        u é de corte;
}

int main () {

}

