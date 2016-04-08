#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

int n; 
char s[15];
pii me[1005][3000], pet[1005];

pii maxi (pii x, pii y) {
    if (x.ss > y.ss) return x;
    else if (x.ss == y.ss) {
        if (x.ff > y.ff) return x;
        else return y;
    }
    return y;
}

pii dp (int i, int pulei) {
    if (i == n) return pii (0, 0);
    if (me[i][pulei] != pii (-1, -1)) return me[i][pulei];
    if (pulei == 0) return me[i][pulei] = pii (dp (i+1, pulei+1).ff + pet[i].ff, dp (i+1, pulei+1).ss);
    else return me[i][pulei] = maxi (pii (dp (i+1, pulei+1).ff + pet[i].ff, dp (i+1, pulei+1).ss), pii (dp (i+1, pulei-1).ff, dp (i+1, pulei-1).ss + pet[i].ss));
}

bool compare (pii x, pii y) {
    if (x.ff != y.ff) return x.ff > y.ff;
    return x.ss < y.ss;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        memset (me, -1, sizeof me);
        scanf ("%d %s", &n, s);
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &pet[i].ff, &pet[i].ss);
        }
        sort (pet, pet + n, compare);
        pii ans;
        if (s[0] == 'P') ans = dp (0, 0); 
        else ans = dp (0, 1);
        printf ("%d %d\n", ans.ff, ans.ss);
    }
}
