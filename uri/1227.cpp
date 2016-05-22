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

int n, a, b, c, sn;
int st[MAX], dis[MAX];
bool seen[MAX];
vector<int> adj[MAX];

bool dfs (int u) {
    if (u == c) return true;
    seen[u] = true;
    bool ans = false;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v] && dfs (v)) {
            st[sn++] = v;
            ans = true; 
        }
    }
    return ans;
}

void distanceA (int u, int d) {
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (dis[v] == -1) {
            dis[v] = d;
            distanceA (v, d+1);
        }
    }
}

int main () {
    while (scanf ("%d %d %d %d", &n, &a, &b, &c) != EOF) {
        sn = 0;
        for (int i = 0; i <= n; i++) 
            seen[i] = false, dis[i] = -1, adj[i].clear ();

        int u, v;
        for (int i = 0; i < n-1; i++) {
            scanf ("%d %d", &u, &v);
            adj[u].pb (v);
            adj[v].pb (u);
        } 
        dfs (b);
        st[sn++] = b;
        dis[a] = 0;
        distanceA (a, 1);
        int menorDisA = INT_MAX;
        double ans = 0;
        for (int i = 0; i < sn; i++) {
            if (dis[st[i]] < menorDisA) {
                menorDisA = dis[st[i]];
                ans = (double) i;
            }
        }
        ans = ans / (sn-1);
        printf ("%.6lf\n", ans); 
    }    
}

