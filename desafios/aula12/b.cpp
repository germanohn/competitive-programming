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

const int MAX = 1005;
const int inf = 1e9;

int n, m;
int d[MAX];
vector<pii> adj[MAX];

bool bellman_ford (int s) {
    for (int i = 0; i < n-1; i++) 
        for (int j = 0; j < n; j++) 
            for (pii v : adj[j]) 
                d[v.ff] = min (d[v.ff], d[j] + v.ss);

    for (int i = 0; i < n; i++) 
        for (pii v : adj[i]) 
            if (d[v.ff] > d[i] + v.ss) 
                return false;

    return true;
}

int main () {
    int c;
    scanf (" %d", &c);
    while (c--) {
        scanf (" %d %d", &n, &m);

        for (int i = 0; i < n; i++) 
            d[i] = inf, adj[i].clear ();
        d[0] = 0;

        for (int i = 0; i < m; i++) {
            int x, y, t;
            scanf (" %d %d %d", &x, &y, &t);
            adj[x].pb (pii (y, t));
        }

        if (!bellman_ford (0)) {
            printf ("possible\n");
        } else {
            printf ("not possible\n");
        }
    }
}

