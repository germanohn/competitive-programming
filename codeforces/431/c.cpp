#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;

int n, k, d;
int me[105][2];

int dp(int w, bool f) {
    if (w == 0) return f;
    if (me[w][f] != -1) return me[w][f];
    int ans = 0;
    bool auxF = f;
    for (int i = 1; i <= min(w, k); i++) {
        if (i >= d) auxF = true;
        ans = (ans + dp(w - i, auxF)) % MOD;
    }
    return me[w][f] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d %d", &n, &k, &d);
    //printf("%d\n", dp(n, 0));

    // iterativo
    printf("%d\n", dp[n][1]);
}

