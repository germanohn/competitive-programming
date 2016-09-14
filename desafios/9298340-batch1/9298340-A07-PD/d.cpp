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

const int MAX = 10;

int n;
int grid[MAX][MAX];

bool ok (int num, int i, int j) {
    bool f = true;

    // linha
    for (int col = 0; f && col < n*n; col++)
        if (col != j && grid[i][col] == num) 
            f = false;

    // coluna
    for (int row = 0; f && row < n*n; row++)
        if (row != i && grid[row][j] == num) 
            f = false;

    // box
    int iniR = n*(i/n), iniC = n*(j/n);
    for (int row = iniR; f && row < iniR+n; row++) 
        for (int col = iniC; f && col < iniC+n; col++) 
            if (row != i && col != j && grid[row][col] == num) 
                f = false;
    return f;
}

bool solve (int i, int j) {
    if (i == n*n) return true;

    bool f = false;
    if (grid[i][j]) {
        if (ok (grid[i][j], i, j)) {
            if (j < n*n - 1) f = solve (i, j+1);
            else f = solve (i+1, 0);
        }
    } else {
        for (int num = 1; !f && num <= n*n; num++) {
            if (!grid[i][j] && !ok (num, i, j)) continue;
            grid[i][j] = num;
            if (j < n*n - 1) f = solve (i, j+1);
            else f = solve (i+1, 0);
            if (!f) grid[i][j] = 0;
        }
    }
    return f;
}

int main () {
    bool f = false;
    while (scanf ("%d", &n) != EOF) {
        if (f) printf ("\n");
        f = true;
        for (int i = 0; i < n*n; i++) 
            for (int j = 0; j < n*n; j++) 
                scanf ("%d", &grid[i][j]);
        
        if (solve (0, 0)) {
            for (int i = 0; i < n*n; i++) {
                for (int j = 0; j < n*n - 1; j++) 
                    printf ("%d ", grid[i][j]);
                printf ("%d\n", grid[i][n*n - 1]);
            }
        } else {
            printf ("NO SOLUTION\n");
        }
    }
}

