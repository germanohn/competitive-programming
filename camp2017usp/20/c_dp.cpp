#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 205;
const int MOD = 1e9 + 7;

int n, m, four, three;
int dg[N];
int adj[N][N];
ll me[N][4][3];

ll mod(ll x) {
    return (x + MOD) % MOD;
}

ll dp(int i, int qf, int qt) {
    if (i == n) return 0;
    if (qf == 3 && qt == 2) return 1;
    ll & memo = me[i][qf][qt];
    if (memo != -1) return memo;

    ll ans = 0;
    if (qf < 3 && adj[i][four]) 
        ans = mod(ans + dp(i + 1, qf + 1, qt));

    if (qt < 2 && adj[i][three]) 
        ans = mod(ans + dp(i + 1, qf, qt + 1));

    //ans = mod(ans + dp(i + 1, qf, qt));
    
    return memo = ans;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
        dg[a]++;
        dg[b]++;
    }

    for (int i = 0; i < n; i++) 
        printf("dg[%d] %d\n", i + 1, dg[i]);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (dg[i] < 4) continue;
        for (int j = 0; j < n; j++) {
            if (i == j || dg[j] < 3) continue;
            memset(me, -1, sizeof me);
            four = i, three = j;
            printf("four %d three %d ", four + 1, three + 1);
            ans = mod(ans + dp(0, 0, 0));
            printf("ans %d\n", ans);
        }
    }

    printf("%lld\n", ans);
}

