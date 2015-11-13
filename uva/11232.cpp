#include <bits/stdc++.h>

using namespace std;

int w, h;
double x, pi = acos (-1), v1, v2;

int main () {
    while (scanf ("%d %d", &w, &h) && w != 0) {
        x = min (h/(pi+1), (double) w);//pro caso de w ser a altura
        v1 = pi/4* w * x * x;
        v2 = pi/4 * w/pi *w/pi * (h-w/pi);
        printf ("%.3lf\n", max (v1, v2));
      }
}
