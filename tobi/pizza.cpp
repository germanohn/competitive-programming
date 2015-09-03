#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 110

using namespace std;

int n, fatia[MAX], memo[MAX][MAX];

int dp (int i, int quant) {
    if (memo[i][quant] != -1) return memo[i][quant];
    if (i == n - 1) return 0; 
    if (quant + fatia[i] >= 0) {   
        
        int r1 = fatia[i] + dp (i + 1, quant + fatia[i]);
        int r2 = dp (i + 1, quant);
        return memo[i][quant] = max (r1, r2);
    }
    return dp (i + 1, quant);
}

int main () {
    memset (memo, -1, sizeof (memo));
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &fatia[i]);
    for (int i = n; i < 2*n; i++)
        fatia[i] = fatia[i-n];
    for (int i = 0; i < 2*n; i++)
        printf ("%d ", fatia[i]);
    printf ("\n");
    printf ("%d\n", dp (0, 0));
}
