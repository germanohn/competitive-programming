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

const int MAX = 1005;

int n, m;
int cont_row[MAX], cont_col[MAX];
char grid[MAX][MAX];

int main () {
    scanf ("%d %d", &n, &m);
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf (" %c", &grid[i][j]);
            if (grid[i][j] == '*')
                cont_row[i]++, cont_col[j]++, cont++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cont_row[i] + cont_col[j] - (grid[i][j] == '*') == cont) {
                printf ("YES\n");
                printf ("%d %d\n", i+1, j+1);
                return 0;
            }
        }
    }
    printf ("NO\n");
}
