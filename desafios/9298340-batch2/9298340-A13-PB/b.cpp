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

int main() {
    ll n;
    int a, b, c, d, x1, x2, x4, x5;
    scanf (" %lld %d %d %d %d", &n, &a, &b, &c, &d);
    x1 = 1;
    x2 = b-c+1;
    x4 = a-d+1;
    x5 = a+b-c-d+1;
    ll ans = 0;
    while (x1 <= n && x2 <= n && x4 <= n && x5 <= n) {
        if (x2 >= 1 && x4 >= 1 && x5 >= 1)
            ans++;
        x1++, x2++, x4++, x5++;
    } 
    ans *= n;

    printf ("%lld\n", ans);
}

