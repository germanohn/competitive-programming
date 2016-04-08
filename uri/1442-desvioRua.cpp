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
const int INF = 1000000000;

int n, m, t, cs, sn, tempo;
int d[MAX], low[MAX], comp[MAX], st[MAX];
int pai[MAX], sz[MAX];
bool seen[MAX];
vector<int> adj[MAX];

void dfs (int u) {
    seen[u] = true;
    d[u] = low[u] = tempo++;
    st[sn++] = u;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v);
            low[u] = min (low[u], low[v]);
        } else {
            low[u] = min (low[u], low[v]);
        }
    }
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sn];
            comp[a] = cs;
            low[a] = INF;
        } while (a != u);
        cs++;
    }
}

int find (int a) {
    if (a == pai[a]) return a;
    return pai[a] = find (pai[a]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap (a, b);
    pai[b] = pai[a];
    sz[a] += sz[b];
    return true;
}

int main () {
    int u, v;
    while (scanf ("%d %d", &n, &m) != EOF) {
        sn = tempo = cs = 0;
        for (int i = 0; i < n; i++) {
            pai[i] = i, sz[i] = 1; 
            adj[i].clear (), seen[i] = false;
        }
        scanf ("%d %d %d", &u, &v, &t);
        for (int i = 0; i < m-1; i++) {
            scanf ("%d %d %d", &u, &v, &t);
            u--, v--;
            if (t == 1) 
                adj[u].pb (v);
            else {
                adj[u].pb (v);
                adj[v].pb (u);
            }
        //    printf ("u %d v %d\n", u, v);
            join (u, v);
        }
        bool f = false;
        for (int i = 0; i < n; i++) {
          //  printf ("i %d sz[i] %d\n", i, sz[i]);
            if (sz[i] == n) 
                f = true;
        }
        if (!f) {
            printf ("*\n");
            continue;
        }       
        for (int i = 0; i < n; i++) {
            if (!seen[i]) 
                dfs (i);
        }
        if (cs == 1) {
            printf ("-\n");
            continue;
        }
        int q = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size (); j++) {
                int k = adj[i][j];
                if (comp[i] != comp[k]) 
                    q++;
            }
        }
        if (q == cs-1) {
            printf ("2\n");
        } else {
            printf ("1\n");
        }
    }
}

