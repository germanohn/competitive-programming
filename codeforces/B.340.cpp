#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int n, a, zero = 0;
    bool f = false;
    ll ans = 1;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        if (a == 1) {
            if (!f) f = true;
            ans *= ((ll) (zero+1));
            zero = 0;
        }
        else {
            if (f) zero++;
        }
    }
    printf ("%I64d\n", f ? ans : 0);
}
