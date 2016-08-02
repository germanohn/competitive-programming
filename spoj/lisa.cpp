#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 105;

int n;
char s[MAX];
pll me[MAX][MAX];

pll dp (int i, int j) {
    if (j-i == 2) {
        ll a, b;
        a = s[i]-'0', b = s[j]-'0';
        if (s[i+1] == '*') return pll (a*b, a*b);
        else return pll (a+b, a+b);
    }
    if (i == j) {
        ll a = s[i]-'0';
        return pll (a, a);
    }
    if (me[i][j] != pll (-1, -1)) return me[i][j];
    ll one = 1;
    pll ans = pll (0, (one << 63) - 1);
    for (int k = i; k <= j-2; k += 2) {
        if (s[k+1] == '*') {
            ans.ff = max (ans.ff, dp (i, k).ff * dp (k+2, j).ff);
            ans.ss = min (ans.ss, dp (i, k).ss * dp (k+2, j).ss);
        } else {
            ans.ff = max (ans.ff, dp (i, k).ff + dp (k+2, j).ff);
            ans.ss = min (ans.ss, dp (i, k).ss + dp (k+2, j).ss);
        }
    }
    return me[i][j] = ans;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        memset (me, -1, sizeof me);
        scanf ("%s", s);
        n = strlen (s);
        printf ("%lld %lld\n", dp (0, n-1).ff, dp (0, n-1).ss);
    }
}

