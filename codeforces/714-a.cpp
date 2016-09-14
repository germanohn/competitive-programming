#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize


int main () {
    ll l1, l2, r1, r2, k;
    scanf (" %lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);
    if (r1 < l2 || l1 > r2) {
        printf ("0\n");
    } else {
        ll l, r;
        l = max (l1, l2);
        r = min (r1, r2);
        if (k >= l && k <= r) {
            printf ("%lld\n", r-l);
        } else {
            printf ("%lld\n", r-l+1);
        }
    }
}

