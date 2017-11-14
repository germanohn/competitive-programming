#include<bits/stdc++.h>
using namespace std;

const int N = 102;
const int greedy = 0;
const int honest = 1;
const int generous = 2;

int g, n, c;
int dp[2][N][2*N*N], p[N], s[N], t[N];
char aux[33];

int buy(int i, int gc, int sc) {
    int ret = 0, change;
    if(t[i] == greedy) {
        change = (g - s[i])/p[i];
    } else if(t[i] == honest) {
        int resto = (g - s[i]) % p[i];
        if(2*resto >= p[i]) change = (g - s[i] + p[i] - 1) / p[i];
        else change = (g - s[i])/p[i];
    } else { //generous
        change = (g - s[i] + p[i] - 1) / p[i];
    }
    change = change * p[i];
    if(sc >= s[i]) {
        ret = max(ret, 1 + dp[!(i&1)][gc][sc-s[i]]);
        if(t[i] == generous) return ret;
    }
    if(gc > 0)
        ret = max(ret, 1 + dp[!(i&1)][gc-1][sc+change]);
    return ret;
}

int main() {
    scanf("%d %d %d", &g, &c, &n);
    for(int i = 0; i < n; i++) { 
        scanf(" %s %d %d", aux, p+i, s+i);
        if(strcmp(aux, "greedy") == 0) t[i] = greedy;
        else if(strcmp(aux, "honest") == 0) t[i] = honest;
        else t[i] = generous;
    }

    for(int i = n-1; i >= 0; i--)
        for(int gc = 0; gc <= c; gc++)
            for(int sc = 0; sc <= g*c; sc++)
                dp[i&1][gc][sc] = max(dp[!(i&1)][gc][sc], buy(i, gc, sc));

    printf("%d\n", dp[0][c][0]);
}

