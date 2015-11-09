#include <bits/stdc++.h>
using namespace std;

int n, f; 
double pi = acos (-1), eps = 0.001;
int v[10005];

int conta (double m) {
    int q = 0;
    for (int i = 0; i < n; i++) {
        q += v[i]/m;
    }
    return q;
}

int main () {
    scanf ("%d %d", &n, &f);
    for (int i = 0; i <n; i++) {
        scanf ("%d", &v[i]);
        v[i] = pi*v[i]*v[i];
    }
    sort (v, v+n);
    double e = 0, d = v[n-1];
    while (d-e > eps) {
        double m = (e+d+1)/2;
        int ans = conta (m);
        printf ("%d\n", ans);
        if (ans <= f) d = m-1;
        else e = m;
    }
    printf ("%.4lf\n", e);
}
