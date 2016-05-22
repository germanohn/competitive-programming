#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

int ans, n;

int main () {
    scanf ("%d", &n);
    // min 
    ans += 2*(n/7);
    if (n % 7 == 6) ans += 1;
    printf ("%d ", ans);
    // max
    if (n == 1) printf ("1\n");
    else {
        ans = 2;
        n -= 2;
        ans += 2*(n/7);
        if (n % 7 == 6) ans += 1;
        printf ("%d\n", ans);
    }
}
