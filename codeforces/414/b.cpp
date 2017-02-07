#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2005;
const int MOD = 1e9 + 7;

int n, k;
int me[MAX][MAX];

ll dp(int i, int size) {
    if (size == 1) return 1;
    if (me[i][size] != -1) return me[i][size];
    ll ans = 0;
    for (int mul = i; mul <= n; mul += i) 
        ans = (ans + dp(mul, size - 1)) % MOD;
    return me[i][size] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d", &n, &k);
    ll ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = (ans + dp(i, k)) % MOD;
    printf("%d\n", ans);
}

