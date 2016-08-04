#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 130;

int n, m;
int acc[15];
char grid[MAX][15];

int main () {
    while (scanf ("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf (" %s", grid[i]);
        for (int j = 0; j < m; j++) {
            acc[j] = 0;
            for (int i = 0; i < n; i++) 
                acc[j] += grid[i][j]-'0';
        }
        for (int j = 0; j < m; j++)
            printf ("%d ", acc[j]);
        printf ("\n");
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int aux = 150;
            for (int j = 0; j < m; j++) 
                if (grid[i][j] == '1') aux = min (aux, acc[j]);
            ans = max (ans, aux);
        }
        if (n == 1) printf ("0\n");
        else printf ("%d\n", ans);
    }
}

