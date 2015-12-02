#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n, k;
int size[MAX], ans;

int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &size[i]);
    }
    sort (size, size+n);
    ans = size[n-1];
    int dps = n-k;
    for (int i = 0; i < dps; i++) {
        if (size[i]+size[2*dps-1-i] > ans)
            ans = size[i]+size[2*dps-1-i];
    }
    printf ("%d\n", ans);
}
