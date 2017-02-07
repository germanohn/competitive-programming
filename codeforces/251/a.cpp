#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, d;
int x[MAX];
ll me[MAX][3];

ll comb(ll a, ll b) {
    if (a < b) return 0;
    if (b == 0 || a == b) return 1;
    if (me[a][b] != -1) return me[a][b];
    return me[a][b] = comb(a - 1, b) + comb(a - 1, b - 1);
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &x[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int nx = upper_bound(x, x + n, x[i] + d) - x;
        nx--;
        if (nx - i < 2) 
            continue;
        ans += comb(nx - i, 2);
    }
    printf("%lld\n", ans);
}

