#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int inf = 1e8;

int n, m, x, y;
int me[N][N][2];
int cost[N][2];

int dp(int j, int k, int t) {
    if (j == m) return (k >= x) ? 0 : inf;
    if (me[j][k][t] != -1) return me[j][k][t];

    int ans = inf;
    if (k >= x)
        ans = cost[j][t ^ 1] + dp(j + 1, 1, t ^ 1);
    if (k < y)
        ans = min(ans, cost[j][t] + dp(j + 1, k + 1, t));
    
    return me[j][k][t] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d %d %d", &n, &m, &x, &y);
    for (int j = 0; j < m; j++)
        cost[j][0] = cost[j][1] = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf(" %c", &c);
            if (c == '.') 
                cost[j][0]--;
            else
                cost[j][1]--;
        }
    }

    printf("%d\n", min(dp(0, 0, 0), dp(0, 0, 1)));
}

