#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll c = 299792458;

int main() {
    int t;
    ll m;
    scanf(" %d", &t);
    for (int i = 0; i < t; i++) {
        scanf(" %lld", &m);
        printf("Case #%d: %lld\n", i + 1, m * c * c);
    }
}

