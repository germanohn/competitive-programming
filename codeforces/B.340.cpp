#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[105], n;
ll me[105][2][2];

ll dp (int i, int q, bool f) {
    if (i == n) {
        if (q == 1) {
            printf ("oi\n");
            return 1;
        }
        return 0;
    }
    int ant = q;
    if (v[i+1] == 1) q++;
    if (me[i][ant][f] != -1) return me[i][ant][f];
    if (q == 0) return me[i][ant][f] = dp (i+1, 0, false);
    return me[i][ant][f] = dp (i+1, q, false) + dp (i+1, q-1, true);
}

int main () {
    memset (me, -1, sizeof me);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    int q = 0;
    if (v[0] == 1) q = 1;
    printf ("%I64d\n", dp (0, q, 0));
}
    /*if (me[i][q] != -1) return me[i][q];
    if (v[i] == 1) q++;
    int nxt = 0;
    if (q > 1) return me[i][q] = 0;
    if (v[i+1] == 1) nxt = 1;
    if (q == 0) return me[i][q] = dp (i+1, nxt);
    return me[i][q] = dp (i+1, q+nxt) + dp (i+1, nxt);
}*/
