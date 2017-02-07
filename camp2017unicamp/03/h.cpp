#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-9;

double s, m, p;

double calc(double x) {
    int auxM = m;
    double a, b, auxS = s;
    while (auxM--) {
        a = auxS * p / 100.;
        b = x - a;
        auxS -= b;
    }
    return auxS;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf(" %lf %lf %lf", &s, &m, &p);
    double l = 0, r = s * 100.;
    int iter = 0;
    while (iter++ <= 300) {
        double a, b, c;
        c = (r - l) / 3.;
        a = l + c;
        b = l + 2 * c;
        if (fabs(calc(a)) - fabs(calc(b)) < eps)
            r = b; 
        else 
            l = a;
    }
    printf("%lf\n", l);
}

