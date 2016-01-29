#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef pair<int, int> pii;

struct coor {
    int x, y, pos;
};

coor pto[MAX];

bool compare (coor a, coor b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool colinear (coor a, coor b, coor c) {
    if ((a.x == b.x && a.x == c.x) || (a.y == b.y && a.y == c.y)) return true;
    //printf ("passei\n");
    float m1 = ((float) (b.y-a.y)/(b.x-a.x)), m2 = ((float) (c.y-b.y)/(c.x-b.x));
    if (m1 < 0) m1 *= -1;
    if (m2 < 0) m2 *= -1;
    if (m1 == m2) return true;
    //printf ("os m sao diferentes\n");
    return false;
}

int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d", &pto[i-1].x, &pto[i-1].y);
        pto[i-1].pos = i;
    }
    sort (pto, pto+n, compare);
   /* for (int i = 0; i < n; i++)
        printf ("pto[i].pos %d x %d y %d\n", pto[i].pos, pto[i].x, pto[i].y);
    */for (int i = 0; i < n-2; i++) {
        if (!colinear (pto[i], pto[i+1], pto[i+2])) {
            printf ("%d %d %d\n", pto[i].pos, pto[i+1].pos, pto[i+2].pos);
            return 0;
        }
    }
}
