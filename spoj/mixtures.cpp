#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#define MAX 110

using namespace std;

int pre[MAX][MAX];
int memo[MAX][MAX];
int n;

int dp (int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    if (i == j) return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
        ans =  min (ans, pre[i][k]*pre[k+1][j] + dp (i, k) + dp (k + 1, j)); 
    return memo[i][j] = ans;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        memset (memo, -1, sizeof (memo));
        for (int i = 0; i < n; i++) {
            scanf ("%d", &pre[i][i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int soma = 0;
                for (int k = i; k <= j; k++) 
                    soma += pre[k][k];
                pre[i][j] = soma % 100;
            }
        }
        printf ("%d\n", dp (0, n-1));
    }
}
