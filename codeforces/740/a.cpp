#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e16;

int main () {
    ll n, a, b, c;
    scanf(" %lld %lld %lld %lld", &n, &a, &b, &c);

    ll ans = inf;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                if ((n + (i) + (j*2) + (k*3)) % 4 == 0 && (i*a + j*b + k*c) < ans)
                   ans = i*a + j*b + k*c; 
            }
        }
    }

    printf("%lld\n", ans);
}

