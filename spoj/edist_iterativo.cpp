#include<bits/stdc++.h>
using namespace std;

const int N = 2005;

int t;
char A[N], B[N];
int dp[N][N];

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %s %s", A, B);

        int len_A = strlen(A), len_B = strlen(B);

        for (int i = 0; i < len_A; i++) 
            dp[i][len_B] = N;

        for (int j = 0; j < len_B; j++) 
            dp[len_A][j] = N;

        dp[len_A][len_B] = 0;

        for (int i = len_A - 1; i >= 0; i--) {
            for (int j = len_B - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(1 + dp[i + 1][j + 1], min(1 + dp[i][j + 1], 1 + dp[i + 1][j]));
                }
            }
        }

        printf("%d\n", dp[0][0]);
    }
}

