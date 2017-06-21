#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const double M = 2e10;
const double eps = 1e-9;

int n;
double p;
double a[N], b[N];

bool ok(double t) {
    double need = 0.;
    for (int i = 0; i < n; i++) {
        double lambda = (a[i] * t - b[i]) / p;
        if (lambda < eps) lambda = 0.;
        //printf("lambda %lf\n", lambda);
        need += lambda;
    }

    //printf("need %lf\n", need);
    return need < t + eps;
}

int main () {
    scanf(" %d %lf", &n, &p);

    for (int i = 0; i < n; i++) {
        scanf(" %lf %lf", &a[i], &b[i]);

        /*if (a[i] > p) 
            f = true;
        else if (a[i] == p)
            eq++;*/
    }

    double lo = 0, hi = M;
    int cont = 0;
    while (cont < 300) {
        double mid = (lo + hi) / 2.;
        if (ok(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
        cont++;
    }

    if (lo == M) printf("-1\n");
    else printf("%lf\n", lo);
}

