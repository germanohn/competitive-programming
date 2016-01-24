#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define pb push_back
#define mp make_pair
#define MAX 100005

using namespace std;

int t, n, m, a, b; 
bool vis[MAX];
vector<int> adj[MAX];
long long int ban[MAX], soma, maxi;

void bfs (int s) {
    queue<int> q;
    q.push (s);
    vis[s] = true;
    soma = ban[s];
    while (!q.empty ()) {
        int p = q.front ();
        q.pop ();
        for (int i = 0; i < adj[p].size (); i++) {
            if (vis[adj[p][i]] == false) {
                q.push (adj[p][i]);
                vis[adj[p][i]] = true;
                soma += ban[adj[p][i]];
            }
        }
    }
    if (soma > maxi) maxi = soma;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &m);

        for (int i = 1; i <= n; i++)
            vis[i] = false;

        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b);
            adj[a].pb (b);
            adj[b].pb (a);
        }

        for (int i = 1; i <= n; i++) 
            scanf ("%lld", &ban[i]);
        
        maxi = -1;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == false)
                bfs (i);
        }
        printf ("%lld\n", maxi);
        for (int i = 1; i <= n; i++) 
            adj[i].clear ();
        for (int i = 0; i <= n; i++) 
            ban[i] = 0;
    }
}
