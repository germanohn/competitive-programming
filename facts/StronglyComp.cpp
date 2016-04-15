#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// grafo direcionado
// aresta de cruzamento: aresta entre um adjacente a mim, mas que já foi visto (não é meu filho na arvore de dfs) e teve a sua recursao terminada
// por isso que no else se faz low[u] = min (low[u], low[v]), mas poderia ser d[v] tambem
// aresta de retorno: aresta entre um adjacente a mim, mas que já foi visto e não teve a sua recursao terminada

int time = 0, sn = 0;

void dfs (int u) {
    seen[u] = true;
    st[sn++] = u;
    d[u] = low[u] = time++;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v);
            low[u] = min (low[u], low[v]);
        } else {
            // pode ser tanto low[v] ou d[v]
            // se for low[v] entao low[u] ira guardar o menor vertice que consigo chegar com numero de arestas variavel
            // se for d[v] entao low[u] ira guardar o menor vertice que consigo chegar com uma unica aresta 
            low[u] = min (low[u], low[v]);
        }
    }
    // u ja foi finalizado
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sn];
            comp[a] = u;
            low[a] = INT_MAX;
        } while (a != u) 
    }
}

void dfs (int u) {
    // 
    for (int e = head[u]; e != 0; e = nx[e]) {
        int v = to[e];
    }
}

/* head[u] é o identificador da primeira aresta de */

int main () {
    int n, u, v, es = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &u, &v);
        to[es] = v;
        nx[es] = head[u];
        head[u] = es++;
        to[es] = u;
        nx[es] = head[v];
        head[v] = es++;
    }
}

