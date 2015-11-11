#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ans;

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n*m; i++) {
        scanf ("%d %d", &a, &b);
        ans += a||b;
    }
    printf ("%d\n", ans);
}
