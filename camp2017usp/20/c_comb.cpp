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
int adj[N][N], qc[N][N];

ll mod(ll x) {
    return (x + MOD) % MOD;
}

ll fexp(ll b, ll e) {
    while (e > 1ll) {
        b = mod(b * b);
        if (e % 2ll == 1ll) 
            b = mod(b * b);
        e /= 2ll;
    }
    return b;
}

ll bin(ll x, ll k) {
    return mod(fat[x] * fexp(fat[x - k] * fat[k], MOD - 2));
}

int main () {
    scanf(" %d %d", &n, &m);
    fat[0] = 1ll;
    for (int i = 1; i <= n; i++)
        fat[i] = mod(fat[i - 1] * ll(i));

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
        dg[a]++;
        dg[b]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            for (int k = j + 1; k < adj[i].size(); k++) {
                qc[j][k]++;
                qc[k][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) 
        printf("dg[%d] %d\n", i + 1, dg[i]);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (dg[i] < 4) continue;
        for (int j = 0; j < n; j++) {
            if (i == j || dg[j] < 3) continue;
            four = i, three = j;
            printf("four %d three %d ", four + 1, three + 1);

            int qi = dg[i] - qc[i][j] - 1;
            int qj = dg[j] - qc[i][j] - 1;

            for (int gi = 0; gi <= qc[i][j]; gi++) {
                for (int gj = 0; gj <= qc[i][j] - gi; gj++) {
                    ans = mod(ans + mod(bin(qi + gi, 3) * bin(qj + gj, 2)));
                }
            }
        }
    }

    printf("%lld\n", ans);
}


