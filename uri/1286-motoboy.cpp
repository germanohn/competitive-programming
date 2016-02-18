#include <bits/stdc++.h>
using namespace std;

int n, p;
int me[25][35], t[25], ped[25];

int dp (int i, int k) {
    if (me[i][k] != -1) return me[i][k];
    if (i == n) return 0;
    if (k + ped[i] <= p) 
        return me[i][k] = max (t[i] + dp (i + 1, k + ped[i]), dp (i + 1, k));
    return me[i][k] = dp (i + 1, k);
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        scanf ("%d", &p);
        memset (me, -1, sizeof (me));
        for (int i = 0; i < n; i++) 
            scanf ("%d %d", &t[i], &ped[i]);
        printf ("%d min.\n", dp (0, 0));
    }
}
