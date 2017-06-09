#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, l, r;
int rest[100];

int main () {
    scanf(" %lld %lld %lld", &n, &l, &r);
    int p = 0;
    if (n == 0ll) {
        printf("0\n");
        return 0;
    }
    if (n == 1ll) {
        printf("1\n");
        return 0;
    }
    while (n > 1) {
        rest[p++] = n % 2;
        n /= 2;
    }
    p--;
    ll ans = r - l + 1;
    ll ratio = 4, ini = 2;
    for (int i = p; i >= 0; i--) {
        if (ini > r)
            break;
        if (rest[i] == 0) {
            ll L, R;
            L = (l - ini + ratio);
            if (L % ratio == 0) L /= ratio, L--;
            else L /= ratio;
            R = (r - ini + ratio) / ratio;
            ans -= (R - L);
        }
        ratio *= 2, ini *= 2;
    }
    printf("%lld\n", ans);
}
