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

const int MAX = 105;
const int MOD = 100;

int n;
int v[MAX], acc[MAX];
int me[MAX][MAX];

int dp (int i, int j) {
    if (i == j) 
        return 0;
    if (me[i][j] != -1) return me[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int a, b;
        a = (acc[k+1]-acc[i])%MOD;
        b = (acc[j+1]-acc[k+1])%MOD;
        ans = min (ans, a*b + dp (i, k) + dp (k+1, j));
    }
    return me[i][j] = ans;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        memset (me, -1, sizeof me);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            acc[i+1] = v[i] + acc[i];
        }
        printf ("%d\n", dp (0, n-1));
    }
}

