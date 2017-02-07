#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dp[2][2][1 << 20];
ll dp2[2][2][1 << 20];
int n, m;
char s[22], t[22];

ll go() {
    for(int mask = 0; mask < (1 << 20); mask++)
        for(int pre = 0; pre < 2; pre++) {
            dp[pre][n&1][mask] = !!mask;
            dp2[pre][m&1][mask] = !!mask;
        }

    for(int i = n-1; i >= 0; i--) {
        for(int mask = 0; mask < (1 << 20); mask++) {
            bool noob = true;
            for(int d = 0; d < 10 && noob; d++) 
                if((mask & (1 << (d+10)) && !(mask & (1 << d)))) noob = false;
            if(!noob) continue;
            for(int pre = 0; pre < 2; pre++) {
                dp[pre][i&1][mask] = !mask ? dp[0][!(i&1)][mask] : 0;       
                if(i < m) dp2[pre][i&1][mask] = !mask ? dp2[0][!(i&1)][mask] : 0;       
                for(int d = 0; d < 10; d++) {
                    if(!mask && !d) continue;
                    if(!(mask & (1 << (d+10)))) {
                        int nmask = mask;
                        if(mask & (1 << d)) nmask |= (1 << (d+10));
                        else nmask |= (1 << d);
                        if(!pre || d <= s[i] - '0') dp[pre][i&1][mask] += dp[pre && (s[i] - '0' == d)][!(i&1)][nmask];
                        if(i < m && (!pre || d <= t[i] - '0')) dp2[pre][i&1][mask] += dp2[pre && (t[i] - '0' == d)][!(i&1)][nmask];
                    }
                }
            }
        }
    }
    return dp[true][0][0] - dp2[true][0][0];
}

int main () {
    freopen("exchange.in", "r", stdin);
    freopen("exchange.out", "w", stdout);
    ll l, r;
    scanf("%lld %lld", &l, &r);
    sprintf(s, "%lld", r);
    sprintf(t, "%lld", l-1);
    n = strlen(s);
    m = strlen(t);
    printf("%lld\n", go());
}

