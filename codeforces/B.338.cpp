#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
using namespace std;
typedef long long ll;

ll ma;
vector<ll> adj[MAX];

void dfs (ll n, ll cont) {
    //vis[n] = true;
    ll tam = cont * (adj[n].size ());
    ma = max (ma, tam);
    for (int i = 0; i < adj[n].size (); i++) {
        int nx = adj[n][i];
        if (nx > n) {
            //printf ("n %d nx %d\n", n, nx);
            dfs (nx, cont+1);
        }

    }
        //printf ("n %d size %d cont %d tam %d\n", n, adj[n].size (), cont, tam);
}

int main () {
    ll n, m, a, b;
    ma = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i].clear ();
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb (b);
        adj[b].pb (a);
    }
    for (int i = 1; i <= n; i++) {
        //for (int j = 1; j <= n; j++) vis[j] = false;
        //printf ("no %d\n\n", i);
        dfs (i, 1);
        //printf ("ma %d\n\n\n", ma);
    }
    cout << ma << "\n";
}
