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

int t, n;
char tab[MAX][MAX];
bool seen[MAX];
vector<int> adj[MAX];

void dfs (int u, int forbid) {
    seen[u] = true;
    if (u == forbid) 
        return;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) 
            dfs (v, forbid);
    }
}

int main () {
    int cont = 1;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) 
            seen[i] = false, adj[i].clear ();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf (" %c", &tab[i][j]);
                if (tab[i][j] == '1') 
                    adj[i].pb (j);
            }
        }
        for (int col = 0; col < n; col++) {
            dfs (0, -1);
            // se nao for alcancado por 0 entao col nao é dominado por ninguem
            if (seen[col]) {
                for (int row = 0; row < n; row++) {
                    if (col == row) {
                        tab[row][col] = 'Y';
                    } else {
                        for (int l = 0; l < n; l++)
                            seen[l] = false;
                        dfs (0, row);
                        // se col é alcancado por 0 desligando row entao row
                        // nao domina col. senao row domina col.
                        if (seen[col])
                            tab[row][col] = 'N';
                        else 
                            tab[row][col] = 'Y';
                    }
                }
            } else {
                // col nao é dominado por ninguem pois nao é alcaçado por 0
                for (int row = 0; row < n; row++) 
                    tab[row][col] = 'N';
            }
            for (int l = 0; l < n; l++) 
                seen[l] = false;
        }
        // layout de saida
        printf ("Case %d:\n", cont++);
        for (int i = 0; i < n; i++) {
            printf ("+");
            for (int l = 0; l < 2*n-1; l++)
                printf ("-");
            printf ("+\n");
            for (int j = 0; j < n; j++) {
                printf ("|%c", tab[i][j]);    
            }
            printf ("|\n");
        }
        printf ("+");
        for (int l = 0; l < 2*n-1; l++)
            printf ("-");
        printf ("+\n");
    }
}

