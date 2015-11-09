#include <bits/stdc++.h>
using namespace std;

/* direcoes: 0-norte, 1-leste, 2-sul, 3-oeste*/

int n, m, k;
int rx, ry, g1x, g1y, g2x, g2y;

int dis (int pos, int dir) {
    if (dir == 0 || dir == 3)
        return pos-1;
    else if (dir == 1)
        return m-pos;
    else if (dir == 2)
        return n-pos;
}

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    while (k--) {
        int dr, dg1, dg2;
        scanf ("%d %d %d %d %d %d", &rx, &ry, &g1x, &g1y, &g2x, &g2y);
        dr = dis (rx, 0), dg1 = dis (g1x, 0), dg2 = dis (g2x, 0);
        //printf ("por norte dr %d dg1 %d dg2 %d\n", dr, dg1, dg2);
        if (dr < dg1+abs (ry-g1y) && dr < dg2+abs (ry-g2y)) {
            printf ("YES\n");
            continue;
        }
        dr = dis (ry, 1), dg1 = dis (g1y, 1), dg2 = dis (g2y, 1);
        //printf ("por leste dr %d dg1 %d dg2 %d\n", dr, dg1, dg2);
        if (dr < dg1+abs (rx-g1x) && dr < dg2+abs (rx-g2x)) {
            printf ("YES\n");
            continue;
        }
        dr = dis (rx, 2), dg1 = dis (g1x, 2), dg2 = dis (g2x, 2);
        //printf ("por sul dr %d dg1 %d dg2 %d\n", dr, dg1, dg2);
        if (dr < dg1+abs (ry-g1y) && dr < dg2+abs (ry-g2y)) {
            printf ("YES\n");
            continue;
        }
        dr = dis (ry, 3), dg1 = dis (g1y, 3), dg2 = dis (g2y, 3);
        //printf ("por oeste dr %d dg1 %d dg2 %d\n", dr, dg1, dg2);
        if (dr < dg1+abs (rx-g1x) && dr < dg2+abs (rx-g2x)) {
            printf ("YES\n");
            continue;
        } 
        printf ("NO\n");
    } 
}
