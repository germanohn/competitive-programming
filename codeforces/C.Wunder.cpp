#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long ll;

struct coor {
    int x, y, pos;
};

coor pto[MAX];

bool compare (coor a, coor b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool colinear (coor a, coor b, coor c) {
    if (((ll) (b.y-a.y)*(c.x-b.x)) == ((ll) (b.x-a.x)*(c.y-b.y))) return true;
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
    for (int i = 0; i < n-2; i++) {
        if (!colinear (pto[i], pto[i+1], pto[i+2])) {
            printf ("%d %d %d\n", pto[i].pos, pto[i+1].pos, pto[i+2].pos);
            return 0;
        }
    }
}
