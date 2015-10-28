#include <bits/stdc++.h>
using namespace std;

double l, p, q;
double d;

int main () {
    scanf ("%lf %lf %lf", &l, &p, &q);
    d = (l/(p+q))*p;
    printf ("%.4lf\n", d);
}
