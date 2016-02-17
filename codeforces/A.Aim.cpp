#include <bits/stdc++.h>
using namespace std;

int d, l, v1, v2, v;

int main () {
    scanf ("%d %d %d %d", &d, &l, &v1, &v2);
    v = v1+v2;
    double t = ((double) l-d)/v;
    printf ("%lf\n", t);
}
