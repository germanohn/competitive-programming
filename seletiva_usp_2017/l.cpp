#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e2 + 5;

int n, m, k;
char text[N], pat[M];
int dp[N][M];

int main() {
    scanf(" %d %d %d", &m, &n, &k);
    scanf(" %s %s", pat, text);

    for (int i = 0; i < n; i++) 
        dp[i][m] = 0;
    for (int j = 0; j < m; j++) 
        dp[n][j] = m - j;
    dp[n][m] = 0;

    for (int j = n - 1; j >= 0; j--) {
        for (int k = m - 1; k >= 0; k--) {
            if (text[j] == pat[k]) {
                dp[j][k] = dp[j + 1][k + 1];
            } else {
                dp[j][k] = 1 + min(dp[j + 1][k + 1], min(dp[j + 1][k], dp[j][k + 1]));
            }
        }
    }

    int ans = N;
    for (int i = 0; i < n; i++) 
        ans = min(ans, dp[i][0]);

    printf("%c\n", (ans <= k) ? 'S' : 'N');
}

