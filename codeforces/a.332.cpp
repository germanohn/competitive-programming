#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

int main () {
    scanf ("%I64d %I64d %I64d", &a, &b, &c);
    ll n = min (2*a+2*c, 2*b+2*c);
    ll m = min (2*a+2*b, n);
    ll ans = min (m, a+c+b);
    printf ("%I64d\n", ans); 
}
