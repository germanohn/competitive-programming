#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int n, k, l, c, d, p, nl, np; 
    scanf(" %d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

    int tot_liq = k * l;
    int tot_slices = c * d;

    int ans = min(tot_liq / nl, min(tot_slices, p / np));
    ans /= n;

    printf("%d\n", ans);
}

