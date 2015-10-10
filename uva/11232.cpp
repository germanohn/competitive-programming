#include <bits/stdc++.h>

using namespace std;

int w, h, vol, y, menor;
double x, pi = acos (-1);

int main () {
    while (scanf ("%d %d", &w, &h) && w != 0) {
        x = min (h / (pi + 1), w / 2);
        vol = pi * ((x * x) / 4) * w;
        y = w / pi;
        if (vol > pi * ((x * x) / 4) * (n - x)))
            printf ("%f\n", x / 2);
        else
            printf ("%f\n", y / 2);
    }
}
