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
const int MAX = 100004;
const int modn = 1000000007;

int n;
ll v[MAX], freq[MAX];
ll me[MAX][3];

ll dp (int i, ant_del) {
    if (i == n) return 0;
    if (me[i][ant_del] != -1) return me[i][ant_del];

    ll ans;

    int nx = i+freq[v[i]];
    if (!ant_del) {
        ans = freq[v[i]] * v[i];
        if (v[nx] == v[i]+1) {
            ans += dp (nx + freq[v[i+freq[v[i]]]]);
        } else {
            ans += dp (nx, 0); 
        }
    } else {
        
    }


    return me[i][ant_del] = ans;
}

int main() {
    scanf ("%d", &n);
    memset (me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        freq[v[i]]++;
    }
    sort (v, v+n);
    v[n] = -1;
    printf ("%lld\n", dp (0));
}

