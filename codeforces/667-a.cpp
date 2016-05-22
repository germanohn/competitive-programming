#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double area, d, h, v, e, E;
double eps = 1e-5;
double pi = acos (-1);

int main () {
    scanf ("%lf %lf %lf %lf", &d, &h, &v, &e);
    area = pi * (d/2) * (d/2);
    E = v * (1 / area);
    if (e - E > eps) {
        printf ("NO\n");
    } else {
        double rate = E-e;
        double ans = h / rate;
        printf ("YES\n");
        printf ("%lf\n", ans);
    }
}

