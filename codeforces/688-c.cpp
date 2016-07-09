#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 1e5 + 5;

int n, m;
int mark[MAX];
bool seen[MAX], f;
vector<int> adj[MAX];

void dfs (int u) {
    seen[u] = true;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            if (mark[u] == 1)
                mark[v] = 2;
            else 
                mark[v] = 1;
            dfs (v);
        } else {
            if (mark[v] == mark[u]) {
                f = false;
                return;
            }
        }
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    f = true;
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &u, &v);
        adj[u].pb (v);
        adj[v].pb (u);
    }
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            mark[i] = 1;
            dfs (i);
        }
    }
    if (!f) {
        printf ("-1\n");
    } else {
        int qtdA = 0, qtdB = 0;
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 1) 
                qtdA++;
            else if (mark[i] == 2)
                qtdB++;
        }
        printf ("%d\n", qtdA);
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 1)
                printf ("%d ", i);
        }
        printf ("\n");
        printf ("%d\n", qtdB);
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 2) 
                printf ("%d ", i);
        }
        printf ("\n");
    }
}

