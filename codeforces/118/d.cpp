#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e8;

int n1, n2, k1, k2;
int me[105][105][15][15];

int dp(int a, int b, int qa, int qb) {
    if (!a && !b) return 1;
    if ((!a && !qb) || (!b && !qa)) return 0;
    if (me[a][b][qa][qb] != -1) return me[a][b][qa][qb];
    int ans = 0;
    if (qa && a) 
        ans = (ans + dp(a - 1, b, qa - 1, k2)) % MOD;
    if (qb && b) 
        ans = (ans + dp(a, b - 1, k1, qb - 1)) % MOD;
    return me[a][b][qa][qb] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d %d %d", &n1, &n2, &k1, &k2);
    printf("%d\n", dp(n1, n2, k1, k2));
}

