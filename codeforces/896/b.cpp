#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    ll k, p;
    scanf(" %lld %lld", &k, &p);

    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        ll aux = i, num = i;
        while (aux > 0) {
            num = num * 10ll + aux % 10;
            aux /= 10;
        }
        ans = (ans + num) % p;
    }

    printf("%lld\n", ans);
}

