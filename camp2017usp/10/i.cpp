#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1123456;

ll v[MAXN];
ll dp[MAXN][7];

int main () {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    for(int i = 0; i < 7; i++)
        dp[0][i] = -1;
    dp[0][0] = 0;
    for(int k = 1; k <= n; k++) {
        int m = v[k-1] % 7;
        for(int i = 0; i < 7; i++) {
            int comp = (7 - m + i + 21) % 7;
            if(dp[k-1][comp] != -1)
                dp[k][i] = max(dp[k-1][comp] + v[k-1],dp[k-1][i]);
            else
                dp[k][i] = dp[k-1][i];
        }
    }
    printf("%lld\n",dp[n][0]);
    return 0;
}

