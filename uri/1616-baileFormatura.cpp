#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int B, G;
int me[1005][1005];

int dp (int b, int g) {
    if (b == 0) return g == 0;
    if (me[b][g] != -1) return me[b][g];
    int ans = 0;
    ans += ((ll) dp (b-1, g-1)) * ((ll) g) % MOD;
    ans += (dp (b-1, g) * (G-g)) % MOD;
    return me[b][g] = ans;
}

int main () {
    while (scanf ("%d %d", &B, &G) && B != 0 && G != 0) {
        memset (me, -1, sizeof me);
        printf ("%d\n", dp (B, G));
    }
}
