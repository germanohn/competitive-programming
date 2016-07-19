#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 205;
const int mod = 1e9 + 7;

int n, cont;
int ans[MAX], v[MAX];

void lexic (int l, int r) {
    if (l == r) return;
    sort (v+l, v+r+1);
    int m = (l+r)/2;
    swap (v[m], v[r-1]);
    cont += r-l;
    lexic (l, m), lexic (m+1, r);
}

ll fexp (ll x, ll y) {
    if (y == 0) return 1; 
    else if (y == 1) return x;
    else if (y % 2 == 0) return (fexp ((x*x) % mod, y/2)) % mod;
    return (x*fexp ((x*x) % mod, y/2)) % mod;
}

ll fatorial (ll x) {
    ll fat = 1;
    while (x > 1) fat = (fat * x) % mod, x--;
    return fat;
}

ll calc (ll n) {
    if (n == 0 || n == 1) return 1;
    ll num, deno, comb, ans;
    num = fatorial (n-2);
    deno = ((fatorial ((n-2)/2) * fatorial (n-2 - (n-2)/2))) % mod;
    comb = (num * fexp (deno, mod-2)) % mod;
    ans = (calc (n/2) * calc ((n+1)/2)) % mod; 
    return (2 * ((ans * comb) % mod)) % mod;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) 
        v[i] = i;
    lexic (1, n);
    for (int i = 1; i <= n; i++)
        ans[i] = v[i];
    printf ("%d\n", cont);
    for (int i = 1; i <= n; i++)
        printf ("%d ", ans[i]);
    printf ("\n");
    printf ("%lld\n", calc (n));
}


