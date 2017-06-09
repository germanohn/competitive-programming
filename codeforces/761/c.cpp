#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;

int n, m;
int me[N][10], cost[N][3];

int dp(int i, int mask) {
    if (i == n) return (mask == 7) ? 0 : 4 * N;
    if (me[i][mask] != -1) return me[i][mask];
    int ans = dp(i + 1, mask);
    if ((mask & 1) == 0) ans = min(ans, cost[i][0] + dp(i + 1, mask | 1));
    if ((mask & 2) == 0) ans = min(ans, cost[i][1] + dp(i + 1, mask | 2));
    if ((mask & 4) == 0) ans = min(ans, cost[i][2] + dp(i + 1, mask | 4));
    return me[i][mask] = ans;
}

int main () {
    scanf(" %d %d", &n, &m);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        cost[i][0] = cost[i][1] = cost[i][2] = N;
        for (int j = 0; j < m; j++) {
            char c;
            scanf(" %c", &c);
            if (isdigit(c)) 
                cost[i][0] = min(cost[i][0], min(j, m - j));
            if (islower(c))
                cost[i][1] = min(cost[i][1], min(j, m - j));
            if (c == '#' || c == '*' || c == '&')
                cost[i][2] = min(cost[i][2], min(j, m - j));
        }
    }
    printf("%d\n", dp(0, 0));
}

