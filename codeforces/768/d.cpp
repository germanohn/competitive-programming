#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const double eps = 1e-7;

int q;
ll k;
double dp[2][N];
int ans[N];

int main() {
    scanf(" %lld %d", &k, &q);

    dp[0][0] = 2000.;

    int p_i = 1;
    bool cur = 0;
    for (int d = 1; p_i <= 1000; d++) {
        cur = !cur;
        dp[cur][0] = 0.;
        for (ll j = 1; j <= k; j++) 
            dp[cur][j] = double(dp[!cur][j] * j + dp[!cur][j - 1] * (k - (j - 1))) / double(k);

        while (p_i <= 1000 && dp[cur][k] > p_i - eps) 
            ans[p_i++] = d;
    }

    while (q--) {
        scanf(" %d", &p_i);
        printf("%d\n", ans[p_i]);
    }
}
