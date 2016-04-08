#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, cesar, p, q;
bool seen[MAX];
pii dis[MAX];
vector<int> adj[MAX];

pii maxi (pii a, pii b) {
    if (a.ff > b.ff) return a;
    else if (a.ff == b.ff) {
        if (a.ss < b.ss && a.ss != cesar) return a;
        else return b;
    } 
    else return b;
}

pii dfs (int u) {
    if (adj[u].size() == 0)
        return dis[u] = pii(0,u);
    dis[u] = pii(-1,-1);  
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        dis[u] = maxi (dis[u], dfs (v));
    }
    dis[u].ff++;
    return dis[u];
}

int main () {
    int test = 1;
    while (scanf ("%d", &n) && n != 0) {
        scanf ("%d", &cesar);
        for (int i = 1; i <= n; i++)
            adj[i].clear (), dis[i] = pii (0, 0);
        while (scanf ("%d %d", &p, &q) && p != 0 && q != 0) 
            adj[p].pb (q);
        dfs (cesar);
        printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", test++, cesar, dis[cesar].ff, dis[cesar].ss); 
    }
}

