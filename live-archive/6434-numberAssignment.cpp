#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000000000;
inline ll mod (ll x) { return x % modn; }

int t, n, m;
ll seq[105], me[105][105][105];

ll dp (int i, int ult, int g) {
    if (i == n-1) {
        if (g == m-1) return seq[i] - seq[ult];
        return modn;
    }
    if (me[i][ult][g] != -1) return me[i][ult][g];
    //ll r1 = dp (i+1, i+1, g+1);
    //ll r2 = dp (i+1, ult, g);
    //if (r1 == 0) printf ("i %d ult %d g %d\n", i, ult, g);
    return me[i][ult][g] = min (seq[i] - seq[ult] + dp (i+1, i+1, g+1), dp (i+1, ult, g));
}

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        memset (me, -1, sizeof me);
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++) 
            scanf ("%lld", &seq[i]);
        sort (seq, seq+n);
        printf ("Case #%d: %lld\n", cont++, dp (0, 0, 0));
    }
}
