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

const int MAX = 505;

int n;
ll grid[MAX][MAX];
pii empty;

int main () {
    scanf (" %d", &n);
    if (n == 1) {
        scanf ("%lld", &grid[0][0]);
        printf ("1\n");
        return 0;
    }
    ll acc = -1;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        bool zero = false;
        for (int j = 0; j < n; j++) {
            scanf (" %lld", &grid[i][j]);
            if (grid[i][j] == 0) empty.ff = i, empty.ss = j, zero = true;
            if (!zero) sum += grid[i][j];
        }
        if (!zero && acc == -1) acc = sum;
    }
    
    bool ok = true;
    ll ans = 0, sum = 0;
    for (int j = 0; j < n; j++) 
        sum += grid[empty.ff][j];

    if (acc > sum) ans = acc-sum, grid[empty.ff][empty.ss] = ans;
    else ok = false;

    ll sumDiag1 = 0, sumDiag2 = 0;
    for (int i = 0; ok && i < n; i++) {
        ll sumRow = 0, sumCol = 0;
        for (int j = 0; j < n; j++) {
            sumRow += grid[i][j], sumCol += grid[j][i];

            if (i == j) sumDiag1 += grid[i][j];
            if (i+j == n-1) sumDiag2 += grid[i][j];
        }
        if (sumRow != acc || sumCol != acc) ok = false;
    }
    if (sumDiag1 != acc || sumDiag2 != acc) ok = false;

    if (!ok) printf ("-1\n");
    else cout << ans << endl;
}

