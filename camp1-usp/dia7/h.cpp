#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 205;
const int inf = 1e9;

int n, m;
char grid[MAX][MAX];

bool calc (int iRow, int row, int jCol, int col) {
    int minI = inf, mxI = -1, minJ = inf, mxJ = -1;
    int cont = 0;
    for (int i = iRow; i < row; i++) {
        for (int j = jCol; j < col; j++) {
            if (grid[i][j] == '#') {
                minI = min (minI, i), mxI = max (mxI, i);
                minJ = min (minJ, j), mxJ = max (mxJ, j);
                cont++;
            }
        }
    }
    if ((mxJ-minJ+1) * (mxI-minI+1) != cont) return false;
    return true;
}


int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf (" %c", &grid[i][j]);

    int row = 0;
    while (row < n) {
        if (!calc (0, row+1, 0, m) || !calc (row+1, n, 0, m)) {
            row++;
            continue;
        }
        printf ("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (grid[i][j] == '#') {
                    if (i <= row) printf ("a");
                    else printf ("b");
                } else printf (".");
            }
            printf ("\n");
        }
        return 0;
    }

    int col = 0; 
    while (col < m) {
        if (!calc (0, n, 0, col+1) || !calc (0, n, col+1, m)) {
            col++;
            continue;
        }
        printf ("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (grid[i][j] == '#') {
                    if (j <= col) printf ("a");
                    else printf ("b");
                } else printf (".");
            }
            printf ("\n");
        }
        return 0;
    }
    printf ("NO\n");
}

