#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

ll satis[20], M[25][25], me[25][1000005];
int n, m, k;

ll dp (int i, int bitmask) {
    if (__builtin_popcount (bitmask) == m) return 0;
    if (me[i][bitmask] != -1) return me[i][bitmask];
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        if (!(bitmask & (1 << j))) {
            ans = max (ans, satis[j] + M[i][j] + dp (j, bitmask | (1 << j)));
        }
    }
    return me[i][bitmask] = ans;
}

int main () {
    memset (me, -1, sizeof me);
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) 
        cin >> satis[i];
    for (int i = 0; i < k; i++) {
        int x, y, c;
        scanf ("%d %d %d", &x, &y, &c);
        M[x][y] = c;
    }
    cout << dp (0, 0) << endl;
}
