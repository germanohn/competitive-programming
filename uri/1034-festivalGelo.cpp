#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int t, n, m, ice[1000005];
int dp[30][1000005];

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++) 
            scanf ("%d", &ice[i]);
        for (int i = 0; i <= 1; i++) dp[i][0] = 0;
        for (int i = 0; i <= m; i++) dp[1][i] = 1000000000;
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j <= m; j++) {
                if (j - ice[i] >= 0) dp[0][j] = min (dp[1][j], 1 + dp[0][j-ice[i]]);
                else dp[0][j] = dp[1][j]; 
            } 
            for (int l = 0; l <= m; l++)
                dp[1][l] = dp[0][l];
        }
        printf ("%d\n", dp[0][m]);
    }
}
