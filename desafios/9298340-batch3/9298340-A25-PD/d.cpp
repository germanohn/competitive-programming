#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int MAXN = 2005;
const int MOD = 1e9 + 7;

int n, m, soares /*aberto*/, sena/*fechado*/;
int me[MAXN][MAXN][2];
char s[MAX];

int dp(int i, int open, bool p_end) {
    if (i == n - m) {
        if (p_end) {
            if (open == 0) return 1;
            return 0;
        }
    } 
    if (me[i][open][p_end] != -1) return me[i][open][p_end];

    int ans = 0;
    if (!p_end) {
        if (open - sena - 1 >= 0 && open - sena - 1 + soares <= 2000)
            ans = (ans + dp(i + 1, open - sena - 1 + soares, true)) % MOD;

        if (open - sena + 1 >= 0 && open - sena + 1 + soares <= 2000)
            ans = (ans + dp(i + 1, open - sena + 1 + soares, true)) % MOD;
    }

    if (i + 1 == n - m && !p_end) 
        return me[i][open][p_end] = ans;

    if (open > 0) 
        ans = (ans + dp(i + 1, open - 1, p_end)) % MOD;
    ans = (ans + dp(i + 1, open + 1, p_end)) % MOD;

    return me[i][open][p_end] = ans;
}

int main() {
    scanf(" %d %d %s", &n, &m, s);
    memset(me, -1, sizeof me);

    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '(') soares++;
        else {
            if (soares > 0) soares--;
            else sena++;            
        }
    }

    int ans = dp(0, 0, false);
    if (sena == 0 && soares <= 2000) ans = (ans + dp(0, soares, true)) % MOD;

    if (n == m && ans != 0) ans--;

    printf("%d\n", ans);
}
