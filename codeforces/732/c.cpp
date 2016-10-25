#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll v[4];
    for (int i = 0; i < 3; i++) 
        scanf(" %lld", &v[i]);
    sort(v, v+3);

    ll ans = 0;
    for (int i = 0; i < 2; i++) {
       ll up = (v[2] - v[i] - 1);
       if (up < 0) up = 0;
       ans += up;
    }

    printf("%lld\n", ans); 
}

