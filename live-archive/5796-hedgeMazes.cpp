#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 10005;

int r, c, q, tempo;
int d[MAX], low[MAX], comp[MAX];
bool seen[MAX];
vector<int> adj[MAX], pte[MAX];
set<int> ponte;

void dfs (int u, int p) {
    seen[u] = true;
    d[u] = low[u] = tempo++;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v] > d[u]) {
                pte[u].pb (v);
                pte[v].pb (u);
                ponte.insert (v);
                ponte.insert (u);
            }
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
}

int dfs (int u) {
    for (int i = 0; i < pte[u].size (); i++) {
        int v = pte[u][i];
        if (comp[v] == -1) {
            comp[v] = comp[u];      
            dfs (v);
        }
    }
}

int main () {
    bool f = false;
    while (scanf ("%d %d %d", &r, &c, &q) && r != 0 && c != 0 && q != 0) {
        if (f) printf ("-\n");
        f = true;
        tempo = 0;
        int u, v;
        for (int i = 1; i <= r; i++) {
            seen[i] = false, adj[i].clear (), pte[i].clear ();
        }
        for (int i = 0; i < c; i++) {
            scanf ("%d %d", &u, &v);
            adj[u].pb (v);
            adj[v].pb (u);
        }
        for (int i = 1; i <= r; i++) {
            comp[i] = -1;
            if (!seen[i]) 
                dfs (i, -1);
        }
        set<int>::iterator it;
        int tam = ponte.size ();
        for (it = ponte.begin (); it != ponte.end (); it++) {
            if (comp[(*it)] == -1) {
                comp[(*it)] = *it;
                dfs ((*it)); 
            }
        }
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &u, &v);
            if (ponte.find (u) != ponte.end () && ponte.find (v) != ponte.end () && comp[u] == comp[v])
               printf ("Y\n");
            else 
               printf ("N\n");  
        }
    }
    printf ("-\n");
}










