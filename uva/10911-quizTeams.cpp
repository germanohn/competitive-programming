#include <bits/stdc++.h>
using namespace std;

int x[20], y[20], n, target;
double dis[20][20], me[1<<16];

double dp (int bitmask) {
    if (me[bitmask] >= 0.0) return me[bitmask];
    if (bitmask == target) return me[bitmask] = 0;
    double ans = 2000000000.0;
    int p1, p2;
    for (p1 = 0; p1 < 2*n; p1++) 
        if (!(bitmask & (1 << p1)))
            break;
    for (p2 = p1 + 1; p2 < 2*n; p2++)
        if (!(bitmask & (1 << p2)))
            ans = min (ans, dis[p1][p2] + dp (bitmask | (1 << p1) | (1 << p2)));
    return me[bitmask] = ans;
}

int main () {
    int caseNo = 1;
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < 2*n; i++) 
            scanf ("%*s %d %d", &x[i], &y[i]);
        for (int i = 0; i < 2 * n -1; i++)
           for (int j = i+1; j < 2*n; j++)
              dis[i][j] = dis[j][i] = hypot (x[i] - x[j], y[i] - y[j]);
       for (int i = 0; i < (1 << 16); i++) me[i] = -1.0;
       target = (1 << (2*n)) - 1;
       printf ("Case %d: %.2lf\n", caseNo++, dp (0)); 
    }
}
