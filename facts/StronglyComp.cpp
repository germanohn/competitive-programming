#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
 - grafo direcionado
 - aresta de cruzamento: dado um vértice u, uma aresta uv é dita de cruzamento, se v é um vértice que 
   além de já ter sido visto, teve sua recursão (sua chamada de dfs: dfs(v)) terminada.
 - por isso que no else se faz low[u] = min (low[u], low[v]), mas poderia ser d[v] tambem
 - aresta de retorno: dado um vértice u, aresta uv é dita de retorno, se v é um vértice já visitado, mas
   que não teve sua recursão (sua chamada de dfs: dfs(v)) terminada ainda. Também pode ser vista como uma aresta para um ancestral.
 - forward edge: aresta para descendente na árvore.
 - Low[u]: maior ancestral de u que consigo alcançar com uma aresta de retorno que pode partir de u ou 
   de um descendente de u (vértice na subárvore de u). Como é direcionado, não precisa se preocupar com aresta 
   pai que tinha no caso de achar ponte.
*/

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
        } else { // agora não tem mais aresta pai, pois é direcionado.
            low[u] = min (low[u], d[v]);
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

