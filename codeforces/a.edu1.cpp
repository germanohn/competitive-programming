#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll tot, n;

int main () {
    scanf ("%d", &t);
    while(t--) {
        scanf ("%I64d", &n);
        tot = n*(1+n)/2;
        for (int i = 1; i <= n; i *= 2) {
            tot -= 2*i;
        } 
        printf ("%I64d\n", tot);
    }
}
