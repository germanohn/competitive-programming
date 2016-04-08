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

int n;
int me[105][105][15];

int dp (int i, int j, int k) {
    if (i == j) return i;
    if (k == 1) return j*(j+1)/2 - i*(i-1)/2;
    if (me[i][j][k] != -1) return me[i][j][k];
    int mi = INT_MAX;
    for (int l = i; l <= j; l++) 
        mi = min (mi, max (dp (i, l-1, k-1) + l, dp (l+1, j, k) + l));
    return me[i][j][k] = mi;
}

int main () {
    int k, m;
    scanf ("%d", &n);
    while (n--) {
        memset (me, -1, sizeof me);
        scanf ("%d %d", &k, &m);
        printf ("%d\n", dp (1, m, k));
    }
}
