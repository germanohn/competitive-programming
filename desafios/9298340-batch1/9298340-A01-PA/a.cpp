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
/////////////////0123456789
const int MAXN = 1004;
const int modn = 1000000007;
const double inf = 1e10;

double v[MAXN];

int main() {
    int n, l;
    scanf ("%d %d", &n, &l);
    for (int i = 0; i < n; i++) 
        scanf ("%lf", &v[i]);
    sort (v, v+n);
    double d = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (n == 1) {
                d = max (d, max (v[0], l-v[0]));
            } else {
                d = max (d, max (v[0], (v[1]-v[0])/2));
            }
        } else if (i == n-1) {
            d = max (d, max ((v[i]-v[i-1])/2, l-v[i]));       
        } else {
            d = max (d, max ((v[i]-v[i-1])/2, (v[i+1]-v[i])/2));       
        }
    }
    printf ("%.10lf\n", d);
}

