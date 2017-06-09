#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e7 + 5;
const ll MOD = 1e9 + 7;

int n;
ll dp[MAX][2];

int main () {
    scanf(" %d", &n);
    dp[1][0] = 0, dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (!j) 
                dp[i][j] = (3 * dp[i - 1][!j]) % MOD;
            else 
                dp[i][j] = (2 * dp[i - 1][j] + dp[i - 1][!j]) % MOD;
        }
    }
    printf("%lld\n", dp[n][0]);
}

