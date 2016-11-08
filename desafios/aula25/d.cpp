#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int MAXN = 2005;
const int MOD = 1e9 + 7;

int n, m, end;
int me[MAXN][2*MAXN];
char s[MAX];

int dp(int i, int qtd_open, bool antes) {
    if (antes && i == end) {
        if (qtd_open >= n - m) 
            antes = 0;
        else return 0;
    }
    if (i == n) 
    if (me[i][qtd_open] != -1) return me[i][qtd_open];

    int ans = 0;
    if (qtd_open > 0) {
        ans = (dp(i + 1, qtd_open - 1) + dp(i + 1, qtd_open + 1)) % MOD;    
    } else {
        ans = dp(i + 1, qtd_open + 1);
    }   

    return me[i][qtd_open] = ans % MOD;
}

int main() {
    scanf(" %d %d %s", &n, &m, s);
    memset(me, -1, sizeof me);

    int qtd_open = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '(') qtd_open++;
        else qtd_open--;
    }

    qtd_open += (n - m);

    int ans = 0;
    antes = true;
    for (int i = 0; i <= n - m; i++) {
        end = i;
        ans = (ans + dp(0, qtd_open, true)) % MOD;
    }

    ans = (ans + dp(n-m, 0, false)) % MOD; 

    printf("%d\n", ans);
}
