#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// grafo sera bidirecionado
// aresta de retorno: aresta entre um adjacente a mim, mas que ja foi visto (nao é meu filho na arvore de dfs) e não teve a sua recursao terminada
// nao tem aresta de cruzamento
// por isso que no else if sera low[u] = min (low[u], d[v]), pois se colocasse low[v] entao poderia acontecer 
// que low[u] fosse menor que d[v], sendo que u nao tem aresta com um vertice anterior a v.

int time;

void dfs (int u, int p) {
    seen[u] = true;
    nf = 0;
    low[u] = d[u] = time++;
    bool any = false;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            nf++;
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v] >= d[u]) 
                any = true;
            if (low[v] == d[v]) 
                uv é ponte;
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
    if (u == raiz && nf >= 2) 
        u é de corte;
    else if (u != raiz && any) 
        u é de corte;
}

int main () {

}

