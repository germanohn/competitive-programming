#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int n, m, c, k;
vector<pii> adj[300];

void solve (int ini) {
    
}

int main () {
    while (scanf ("%d %d %d %d", &n, &m, &c, &k) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) {
            dis[i] = INT_MAX;
            adj[i].clear ();
        }
        
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b, &p);
            adj[a].pb (mp (b, p));
            adj[b].pb (mp (a, p));
        }
        solve (0);
    }
}
