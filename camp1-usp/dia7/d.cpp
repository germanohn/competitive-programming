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
    sort (v+l, v+r);
    int tmp, m = (l+r)/2;
    tmp = v[m], v[m] = v[r-1], v[r-1] = tmp;
    cont += r-l;
    lexic (l, m), lexic (m+1, r);
}

int fexp (ll x, ll y) {
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
    ll num, deno, comb;
    num = fatorial (n-2);
    deno = ((fatorial ((n-2)/2) * fatorial (n-2 - (n-2)/2))) % mod;
    comb = (num * fexp (deno, mod-2)) % mod;
    return 2 * (((calc (n/2) * calc ((n+1)/2) % mod) * comb) % mod);
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




/*void merge (int l, int r) {
    int m = (l+r)/2, k = 0;
    int i = l, j = m+1;
    while (i <= m && j <= r) {
        cont++;
        if (v[i] < v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++]
    }
    while (i <= m) aux[k++] = v[i++];
    while (j <= r) aux[k++] = v[j++];
    for (i = l; i <= r; i++) v[i] = aux[i-l];
}

void mergesort (int l, int r) {
    if (l == r) return;
    int m = (l+r)/2;
    mergesort (l, m);
    mergesort (m+1, r);
    merge (l, r);
}*/
