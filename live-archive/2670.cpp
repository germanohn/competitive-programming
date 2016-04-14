#include <bits/stdc++.h>
using namespace std;

const int INF = 1123456789;

int t;
int v[10], me[7][105];

int dp (int i, int f) {
    if (f == 0) 
        return 0;
    else if (i == 6) 
        return INF;
    if (me[i][f] != -1) return me[i][f];
    int a1, a2 = INF;
    a1 = dp (i+1, f);
    if (v[i] <= f) 
        a2 = min (1 + dp (i+1, f-v[i]), 1 + dp (i, f-v[i]));
    return me[i][f] = min (a1, a2);
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        for (int i = 0; i < 6; i++) 
            scanf ("%d", &v[i]);
        memset (me, -1, sizeof me);
        int sum = 0, mx = -1, tmp;
        for (int i = 1; i <= 100; i++) {
            tmp = dp (0, i);
            printf ("i %d tmp %d\n", i, tmp);
            if (tmp > mx)
                mx = tmp;
            sum += tmp;
        }
        double ans = sum/100;
        printf ("%lf %d\n", ans, mx);
    }
}
