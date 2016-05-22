#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

ll n, t;

ll fexp (ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return (fexp ((x*x) % MOD, y/2)) % MOD;
    return (x * fexp ((x*x) % MOD, y/2)) % MOD;
}

int main () {
    scanf ("%lld", &t);
    while (t--) {
        scanf ("%lld", &n);
        if (n % 2 == 0) {
            printf ("%lld\n", (3ll*fexp (2, n/2) - 2) % MOD);
        } else {
            printf ("%lld\n", (fexp (2, (n+3)/2) - 2) % MOD);
        }
    }    
}

