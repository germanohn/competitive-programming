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
 - grafo será bidirecionado, logo só tem dois tipos de aresta: tree, back
 - aresta de retorno: dado um vértice u, aresta uv é dita de retorno, se v é um vértice já visitado, mas
   que não teve sua recursão (sua chamada de dfs: dfs(v)) terminada ainda.
 - não tem aresta de cruzamento, pois o grafo é bidirecionado
 - por isso que no else if sera low[u] = min (low[u], d[v]), pois se colocasse low[v] entao poderia acontecer 
 - que low[u] fosse menor que d[v], sendo que u nao tem aresta com um vertice anterior a v.
 - Tem duas opções para a aresta uv analisada. Ou é uma aresta da árvore, ou é uma aresta de retorno. 
   As arestas de retorno PAI não devem ser analisadas para o low, porque estamos interessados apenas em 
   arestas de retorno que partem de algum descendente.
*/
/*
 - Uma aresta uv é uma ponte se não existe nenhuma aresta de retorno na subárvore
   de v para um ancestral de u
 - Low[u]: maior ancestral de u que consigo alcançar com uma aresta de retorno (não pai) que pode partir de u ou 
   de um descendente de u (subárvore).
*/


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
            if (low[v] == d[v]) // ou low[v] > d[u] 
                uv é ponte;
        } else if (v != p) { // aresta de retorno não pai
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

