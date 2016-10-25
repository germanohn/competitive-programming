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

const int MAX = 10005;
const int MAXN = 10000000;

int n, m, k;
int gr[MAX], ans[MAXN];
vector<int> adj[MAX];

void dfs (int u) {
    printf ("comecou dfs de %d\n", u);
    while (adj[u].size ()) {
        int v = adj[u].back ();
        adj[u].pop_back ();
        printf ("u %d v %d\n", u, v);
        dfs (v);
    }
    printf ("terminou a dfs de %d\n", u);
    ans[k++] = u;
}

int main () {
    scanf (" %d", &n);
    int a, b, ini;
    while (n--) {
        scanf (" %d", &m);
        scanf (" %d", &a);
        ini = a;
        for (int i = 0; i < m; i++) {
            scanf (" %d", &b);
            adj[a].pb (b);
            gr[a]++;
            gr[b]--;
            a = b;
        }
    }

    dfs (ini);
    printf ("%d", k-1);
    for (int i = k-1; i >= 0; i--) 
        printf (" %d", ans[i]);
    printf ("\n");
}

