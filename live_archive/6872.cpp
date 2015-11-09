#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, v[35];
ll memo[40][40], memo1[40][40][2];

ll dp1 (int i, int sum) {
    if (sum <= 0) return 0;
    if (i == n) return 1;
    ll &m = memo[i][sum];
    if (m != -1) return m;
    ll ans = 0;
    for (int j = 0; j < 31; j++) {
        ans += dp1 (i+1, sum - j);
    }
    return m = ans;
}

ll dp2 (int i, int sum, bool pre) {
    if (sum == 0) return 1;
    if (sum < 0 || i == n) return 0;
    ll &m = memo1[i][sum][pre];
    if (m != -1) return m;
    ll ans = 0;
    for (int j = 0; j < 31; j++) {
        if (pre && j > v[i]) break;
        ans += dp2 (i+1, sum - j, pre && j== v[i]);
    }
    return m = ans;
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        memset (memo, -1, sizeof (memo));
        memset (memo1, -1, sizeof (memo1));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            sum += v[i];
        }
        ll ans = 0;
        ans += dp1 (0, sum);
        ans += dp2 (0, sum, true);
        printf ("%lld\n", ans);
    }
}
