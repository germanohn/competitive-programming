#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, x, y;
double me[N][N];

double comb(double x) {
    return (x * (x - 1)) / 2;
}

double dp(double lo, double hi) {
    double has = lo + hi + 1;
    if (has == y) {
        if (!hi) return (y == 1) ? 1 : 0;
        return hi / comb(has);
    }
    if (has < y) return 0;
    double &m = me[int(lo)][int(hi)];
    if (m != -1.) return m;
 
    m = 0;
    double den = comb(has);
    if (hi >= 2) 
        m += dp(lo, hi - 1) * (comb(hi) / den);
    if (lo >= 2) 
        m += dp(lo - 1, hi) * (comb(lo) / den);
    if (hi && lo) 
        m += dp(lo - 1, hi) * ((lo * hi) / den);
    if (lo) 
        m += dp(lo - 1, hi) * (lo / den);

    return m;
}

int main() {
    while (scanf(" %d %d %d", &n, &x, &y) != EOF) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                me[i][j] = -1;
        printf("%.4lf\n", dp(n - x, x - 1));
    }
}

