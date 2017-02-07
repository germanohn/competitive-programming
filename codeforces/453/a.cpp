#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double n, m;

double fexp(double base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    if (exp % 2 == 0) return fexp(base * base, exp / 2);
    return base * fexp(base * base, exp / 2);
}

int main () {
    scanf(" %lf %lf", &m, &n);
    double ans = 0;
    for (int i = 1; i <= m; i++) {
        double val = i;
        ans += (val * fexp(val / m, n) - val * fexp((val - 1) / m, n));
    }
    printf("%lf\n", ans);
}

