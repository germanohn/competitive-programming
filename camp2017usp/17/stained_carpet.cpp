#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-6;
const double pi = acos(-1);

double a, b, c;

double angle(double l, double x, double y) {
    return acos((-(l * l) + (x * x) + (y * y)) / (2. * x * y));
}

int main () {
    while (scanf(" %lf %lf %lf", &a, &b, &c) != EOF) {
        double lo = max(fabs(a - b), max(fabs(b - c), fabs(a - c)));
        double hi = min(fabs(a + b), min(fabs(b + c), fabs(a + c)));
        int cont = 0;
        while (cont < 300) {
            double mid = (lo + hi) / 2.;
            
            double sum = angle(mid, a, b) + angle(mid, a, c) + angle(mid, b, c);
            if (sum > (2. * pi))
                hi = mid;
            else
                lo = mid;

            cont++;
        }

        if (fabs(angle(lo, a, b) + angle(lo, a, c) + angle(lo, b, c) - (2. * pi)) > eps) 
            printf("-1.000\n");
        else 
            printf("%.3lf\n", (lo * lo * sqrt(3)) / 4.);

    }
}

