#include <bits/stdc++.h>
using namespace std;

int n, f; 
double pi = acos (-1), eps = 1e-7;
double v[10005];

int conta (double m) {
    int q = 0;
    for (int i = 0; i < n; i++) {
        q += v[i]/m;
    }
    return q;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &f);
        // ATENCAO: tem um pedaco pra ele tambem 
        f++;
        for (int i = 0; i <n; i++) {
            scanf ("%lf", &v[i]);
            v[i] = pi*v[i]*v[i];
        }
        sort (v, v+n);
        double e = 0, d = v[n-1];
        int ans;
        while (d-e > eps) {
            double m = (e+d)/2.0;
            ans = conta (m);
            if (ans < f) d = m;
            else e = m;
        }
        printf ("%.4lf\n", e);
    }
}
