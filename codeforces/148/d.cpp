#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

double me[N][N][2];

double prob(double x, double y) {
    return x / y;
}

double dp(int w, int b, bool f) {
    if (!w) return 0;
    if (!b) return f;
    double &m = me[w][b][f];
    if (m != -1) return m;

    printf("w %d b %d f %d\n", w, b, f);
    m = 0;
    if (f) {
        m += prob(w, w + b);
        m += dp(w, b - 1, 0) * prob(b, w + b);
    } else {
        m += dp(w, b - 1, 1) * prob(b, w + b);
        if (w > 2) 
            m += dp(w - 1, b - 1, 1) * prob(w, w + b - 1); 
        else if (b == 1) 
            m = 0;
        if (b > 1) 
            m += dp(w, b - 2, 1) * prob(b - 1, w + b - 1);
    }

    return m;
}

int main() {
    int w, b;
    scanf(" %d %d", &w, &b);
    for (int i = 0; i <= w; i++) 
        for (int j = 0; j <= b; j++)
            me[i][j][0] = me[i][j][1] = -1;
    printf("%.10lf\n", dp(w, b, 1));
}

