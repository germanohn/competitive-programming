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

const int MAX = 105;

int color[MAX];
vector<int> adj[MAX];

int dfs (int u) {
    bool ans = true;
    for (int i = 0; ans && i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (color[v] == -1) {
            if (color[u]) color[v] = 0;
            else color[v] = 1;
            ans = dfs (v);
        } else if (color[v] == color[u]) {
            ans = false;
        } 
    }

    return ans;
}

int main () {
    memset (color, -1, sizeof(color));

    int n;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        while (scanf (" %d", &a) && a != 0) { 
            adj[i+1].pb (a);
            adj[a].pb (i+1);
        }
    }

    color[1] = 0;
    if (dfs (1)) {
        for (int i = 0; i < n; i++) 
            printf ("%d", color[i+1]);
        printf ("\n");
    } else {
        printf ("-1\n");
    }
}

