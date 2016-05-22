#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) //fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<vector<int> > vvi;
typedef vector<vector<piii> > vviii;

const int MAX = 1000005;

int n, m, tempo, cs, sn;
int st[MAX], d[MAX], low[MAX], ans[MAX], comp[MAX], degree[MAX];
bool seen[MAX];
queue<int> q;
vvi grid;
vviii row, col;
vector<int> adj[MAX];
vector<int> adjC[MAX];

int dfs (int u) {
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
            low[a] = INT_MAX;
        } while (a != u);
        cs++;
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    
    grid.assign (n, vector<int> ());
    row.assign (n, vector<piii> ());
    col.assign (m, vector<piii> ());
   
    int a; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%d", &a);
            grid[i].pb (a);
            row[i].pb (piii (a, pii (i, j)));
            col[j].pb (piii (a, pii (i, j)));
        }
    }
    
    for (int i = 0; i < n; i++) 
        sort (row[i].begin (), row[i].end ());
    for (int j = 0; j < m; j++) 
        sort (col[j].begin (), col[j].end ());
    

    int linha, coluna;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = grid[i][j];
            // linha é uma coluna da linha row[i]
            linha = upper_bound (row[i].begin (), row[i].end (), piii (val, pii (n, m))) - row[i].begin ();
            debug("val %d row[i][linha] %d linha %d\n", val, row[i][linha].ff, linha);
            // coluna é uma linha da coluna col[j]
            coluna = upper_bound (col[j].begin (), col[j].end (), piii (val, pii (n, m))) - col[j].begin ();  
            debug("val %d col[j][coluna] %d\n", val, col[j][coluna].ff);
            int x, y;
            if (row[i][linha-1] != piii (val, pii (i, j))) {
                // entao significa que tenho um elemento igual a mim na linha
                // logo tenho que colocar uma aresta de ida e volta
                // vamos mapear os elementos por i*j
                linha--;
                x = row[i][linha].ss.ff;
                y = row[i][linha].ss.ss;
                adj[m*x + y].pb (m*i + j); 
            }
            if (col[j][coluna-1] != piii (val, pii (i, j))) {
                // entao significa que tenho um elemento igual a min na coluna
                // logo tenho que colocar uma aresta de ida e volta
                coluna--;
                x = col[j][coluna].ss.ff;
                y = col[j][coluna].ss.ss;
                // coluna é uma linha que vezes o numero de colunas diz quantas colunas ja passaram
                adj[m*x + y].pb (m*i + j);
            }
            if (linha != m) {
                x = row[i][linha].ss.ff;
                y = row[i][linha].ss.ss;
                // entao o upper_bound nao retornou null
                adj[m*i + j].pb (m*x + y);
            }
            if (coluna != n) {
                x = col[j][coluna].ss.ff;
                y = col[j][coluna].ss.ss;
                adj[m*i + j].pb (m*x + y);
            }
        } 
    }

    // acha as componentes fort conexas
    for (int i = 0; i < n*m; i++) {
        if (!seen[i]) 
            dfs (i);
    }

    // cria o kernel dag
    for (int i = 0; i < n*m; i++) {
        for (int j = 0; j < adj[i].size (); j++) {
            int x = adj[i][j];
            debug("i %d x %d\n", i, x);
            if (comp[i] != comp[x]) {
                degree[comp[x]]++;
                adjC[comp[i]].pb (comp[x]);
            } 
        }
    }   

    // toposort
    int cont = 1;
    for (int i = 0; i < cs; i++) {
        if (degree[i] == 0) {
            q.push (i);
            // valor que terao os vertices da componente
            ans[i] = 1;
        }
    }

    int tam = q.size ();
    debug("q.size () %d\n", tam);
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        for (int i = 0; i < adjC[x].size (); i++) {
            int y = adjC[x][i];
            degree[y]--;
            if (degree[y] == 0) {
                ans[y] = ans[x] + 1;
                q.push (y);
            }
        }
    }

    // preencher a matriz e imprimir
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = ans[comp[m*i + j]];
            printf ("%d ", grid[i][j]);
        }
        printf ("\n");
    }
}

















