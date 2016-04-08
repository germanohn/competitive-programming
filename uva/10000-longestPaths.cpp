#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, p, q, cesar, dis[MAX];
vector<int> adj[MAX];

/* a distancia ate todos os vertices comeca 0. so vou entrar e analisar de novo um
// vertice se a distancia ate ele aumentar*/
int dfs (int u, int d) {
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        // esse é o grande detalhe do exercicio: so vou olhar de novo para um vertice 
        // se a maior distancia ate ele aumentar
        if (dis[v] < d+1) { 
            dis[v] = d+1;
            dfs (v, dis[v]);  
        }
    }
}

int main () {
    int test = 1;
    while (scanf ("%d", &n) && n != 0) {
        scanf ("%d", &cesar);
        while (scanf ("%d %d", &p, &q) && p != 0 && q != 0) 
            adj[p].pb (q);
        for (int i = 1; i <= n; i++) 
           dis[i] = 0, adj[i].clear (); 
        dfs (cesar, 0);
        int maxi = INT_MIN, ind = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (dis[i] > maxi) {
                maxi = dis[i];
                ind = i;
            } else if (dis[i] == maxi && i < ind) {
                ind = i;
            }
        }
        printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", test++, cesar, maxi, ind);
    }
}

