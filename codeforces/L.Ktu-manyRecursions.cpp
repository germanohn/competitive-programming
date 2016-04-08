#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

ll fexp (ll base, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    if (exp % 2 == 0) return fexp ((base*base)%MOD, exp/2);
    return (base * fexp ((base*base)%MOD, exp/2))%MOD;
}

int main () {
    ll a, ans;
    cin >> a;
    ans = fexp (2, a);
    cout << ans << endl;
}

