#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAX = 2004;
const int modn = 1000000007;

int size, n;
ll me[MAX][MAX];
pii v[MAX];

ll dp (int i, int size) {
    if (i == n) return 0;
    if (me[i][size] != -1) return me[i][size];
    ll ans = dp (i+1, size);

    if (size - v[i].ff >= 0) 
        ans = max (ans, v[i].ss + dp (i+1, size - v[i].ff));

    return me[i][size] = ans;
}

int main() {
    scanf (" %d %d", &size, &n);
    memset (me, -1, sizeof me);
    for (int i = 0; i < n; i++) 
        scanf (" %d %d", &v[i].ff, &v[i].ss);

    printf ("%lld\n", dp (0, size));
}

