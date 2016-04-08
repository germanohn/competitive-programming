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

int tam;
ll me[100005];
char s[100005];

ll dp (int i) {
    if (i == tam) return 1;
    ll num = s[i]-'0', ans = 0;
    if (num == 0) return 0;
    if (me[i] != -1) return me[i];
    if (i != tam - 1 && num*10 + s[i+1]-'0' <= 26) ans += dp (i+2);
    ans += dp (i+1);
    return me[i] = ans;
}

/*ll dp (int i, int k) {
    if (i == tam) return 1;
    if (me[i][k] != -1) return me[i][k];
    ll num = s[i]-'0', ans = 0;
    if (k*10 + num <= 26) ans += dp (i+1, k*10 + num);
    if (num != 0) ans += dp (i+1, num);
    return me[i][k] = ans;
}*/

int main () {
    while (scanf (" %s", s) && s[0] != '0') {
        memset (me, -1, sizeof me);
        tam = strlen (s);
        ll ans = dp (0);
        printf ("%lld\n", ans);
    }
}
