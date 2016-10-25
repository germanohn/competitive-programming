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
const int MAXN = 10004;
const int modn = 1000000007;

int n, k, s;
int v[25];
int me[25][15][200];

int dp (int i, int res, int sum) {
    if (res == k) {
        if (sum == s) return 1;
        return 0;
    }
    if (i == n) return 0;

    if (me[i][res][sum] != -1) return me[i][res][sum];

    int ans = dp (i+1, res, sum);
    if (sum + v[i] <= s) {
        ans += dp (i+1, res+1, sum+v[i]);
    }

    return me[i][res][sum] = ans;
}

int main() {
    for (int i = 0; i < 20; i++) 
        v[i] = i+1;

    while (scanf ("%d %d %d", &n, &k, &s)) {
        if (n == 0 && k == 0 && s == 0) break;
        memset (me, -1, sizeof me);
              
        printf ("%d\n", dp (0, 0, 0)); 
    }
}

