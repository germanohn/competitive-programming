#include <bits/stdc++.h>

using namespace std;

int n, ans, a, b;

int main () {
    scanf ("%d", &n);
    int menor = 100;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        menor = min (menor, b);
        ans += menor * a;
    }
    printf ("%d\n", ans);
}
