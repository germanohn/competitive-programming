#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    ll n, a, b;
    scanf(" %lld %lld %lld", &n, &a, &b);
    bool f = true;
    if (a > b) { 
        swap(a, b);
        f = false;
    }
    ll area = a * b;
    ll a1 = a; 
    ll a2 = b;
    for (ll i = a; i * i <= 6ll * n; i++) {
        ll j = ((6ll * n) + i - 1ll) / i;
        if (j >= b && (area < 6ll * n || i * j < area)) {
            area = i * j;
            a1 = i; a2 = j;
        }
    }
    printf("%lld\n", area);
    if (f) printf("%lld %lld\n", min(a1, a2), max(a1, a2));
    else printf("%lld %lld\n", max(a1, a2), min(a1, a2));
}

