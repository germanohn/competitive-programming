#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e4 + 5;

int n, d;
int gem[N];
int dp[N][500];

int main () {
    scanf(" %d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        gem[a]++;
    }

    int x = max(0, d - 245);
    for (int i = 30000; i >= 0; i--) {
        for (int j = max(1, d - 245); j <= d + 245; j++) {
            dp[i][j - x] = gem[i];
            if (i + j - 1 > 30000) 
                continue;
            if (j == 1) {
                dp[i][j - x] += max(dp[i + j][j - x], 
                                    dp[i + j + 1][j + 1 - x]);
            } else {
                dp[i][j - x] += max(dp[i + j - 1][j - 1 - x], 
                                max(dp[i + j][j - x],
                                    dp[i + j + 1][j + 1 - x]));
            }
        }
    }

    printf("%d\n", dp[d][d - x]);
}

