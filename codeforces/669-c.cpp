#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: nao reutilize variaveis do exercicio, atencao com as variaveis dadas 
// como entrada

const int MAX = 105;

int n, m, q, x, kind;
int grid[MAX][MAX]; 
pii shift[MAX][MAX];

void shiftRow (int r) {
    for (int j = 1; j < m; j++) 
        swap (shift[r][j], shift[r][j+1]);
}

void shiftCol (int c) {
    for (int i = 1; i < n; i++) 
        swap (shift[i][c], shift[i+1][c]);
}

int main () {
    int r, c;
    scanf ("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            shift[i][j] = pii (i, j);
    for (int i = 0; i < q; i++) {
        scanf ("%d", &kind);
        if (kind == 1) {
            scanf ("%d", &r);
            shiftRow (r);
        } else if (kind == 2) {
            scanf ("%d", &c);
            shiftCol (c);
        } else {
            scanf ("%d %d %d", &r, &c, &x);
            int a, b;
            a = shift[r][c].ff;
            b = shift[r][c].ss;
            grid[a][b] = x;
        }    
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf ("%d ", grid[i][j]);
        printf ("\n");
    }
}

