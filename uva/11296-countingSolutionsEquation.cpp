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

int main () {
    int n;
    while (scanf ("%d", &n) != EOF) {
        if (n % 2 != 0) n--; 
        ll ans = n/2 + 1;
        ans = (ans * (1 + ans))/2;
        printf ("%lld\n", ans);
    }
}

