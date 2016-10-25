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
const int MAX = 50004;
const int MOD = 1000000007;

int n, a, b;
int me[MAX][3];

int dp (int i, int atual) {
    if (i == n) return 1;
    if (me[i][atual] != -1) return me[i][atual];

    int ans;
    if (atual == 1) {
        ans = 0;
        for (int j = 1; j <= a && i+j <= n; j++) 
            ans = (ans + dp (i+j, 2)) % MOD;
    } else {
        ans = 0;
        for (int j = 1; j <= b && i+j <= n; j++) 
            ans = (ans + dp (i+j, 1)) % MOD;
    }

    return me[i][atual] = ans;
}

int main() {
    scanf (" %d %d %d", &n, &a, &b);
    memset (me, -1, sizeof me);

    int ans = (dp (0, 1) + dp (0, 2)) % MOD;
    printf ("%d\n", ans);
}

