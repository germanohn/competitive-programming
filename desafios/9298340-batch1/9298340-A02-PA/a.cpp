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
    int t, s, x;
    scanf ("%d %d %d", &t, &s, &x);
    if (x < t) printf ("NO\n");
    else if (x >= t && x < t+s) {
        if (x == t) printf ("YES\n");
        else printf ("NO\n");
    } else {
        x -= t;
        if (x % s == 0 || x % s == 1)
            printf ("YES\n");
        else 
            printf ("NO\n");
    }
}
