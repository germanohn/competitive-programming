#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef unsigned long long hash;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

struct ponte {
    char system[15];
    ll sum;
};

int a, b;
pii me[1005][1005];
ponte north[1000005], south[1000005];
char s[15];

pii lcs (int i, int j) {
    if (i == a || j == b) return pii (0, 0);
    if (me[i][j] != pii (-1, -1)) return me[i][j];
    pii ans = pii (0, INT_MIN);
    if (strcmp (north[i].system, south[j].system) == 0) {
        ans = lcs (i+1, j+1);
        ans.ff++;
        ans.ss += north[i].sum + south[j].sum;
    } 
    pii a1 = lcs (i+1, j), a2 = lcs (i, j+1);
    if (a1.ss == a2.ss) {
        if (a1.ff > a2.ff) a1 = a2;
    } 
    else if (a1.ss < a2.ss) a1 = a2;
    if (ans.ss == a1.ss) {
        if (ans.ff > a1.ff) ans = a1;
    }
    else if (ans.ss < a1.ss) ans = a1;
    return me[i][j] = ans;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        memset (me, -1, sizeof me);
        scanf ("%d", &a);
        for (int i = 0; i < a; i++)  
            scanf ("%s %s %lld", s, north[i].system, &north[i].sum);
        scanf ("%d", &b);
        for (int j = 0; j < b; j++) 
            scanf ("%s %s %lld", s, south[j].system, &south[j].sum);
        pii ans = lcs (0, 0);
        printf ("%lld %lld\n", ans.ss, ans.ff);
    }
}

