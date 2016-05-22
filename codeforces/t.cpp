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

int n, m;
int ans[MAX], degree[MAX];
int grid[MAX], l[MAX], c[MAX];
vector<int> adj[MAX], adjC[MAX];

int d (int i, int j) {
    return m*i + j;
}

void topo () {
    queue<int> q;
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
}

int main () {
    scanf ("%d %d", &n, &m); 
    int a; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%d", &a);
            int idx = d (i, j);
            grid[idx] = a;
            l[i].pb (idx);
            c[j].pb (idx);
        }
    }
    
    for (int i = 0; i < n; i++) 
        sort (l[i].begin (), l[i].end ());
    for (int j = 0; j < m; j++) 
        sort (c[j].begin (), c[j].end ());
    
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

    // preencher a matriz e imprimir
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = ans[comp[m*i + j]];
            printf ("%d ", grid[i][j]);
        }
        printf ("\n");
    }
}

















