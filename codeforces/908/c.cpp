#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int eps = 1e-8;

int n, r;
int x[N];
double y[N];

double dist2(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double y_position(int a, int b) {
    double lo = y[b], hi = y[b] + 2 * double(r);
    int cont = 0;
    while (cont < 150) {
        double mid = (lo + hi) / 2.;
        if (dist2(x[a], mid, x[b], y[b]) < 4 * double(r * r) + eps) {
            lo = mid;
        } else {
            hi = mid;
        }
        cont++;
    }
    return lo;
}

int main() {
    scanf(" %d %d", &n, &r);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &x[i]);

    for (int i = 0; i < n; i++) { 
        double y_max = double(r);
        for (int j = 0; j < i; j++) {
            if (abs(x[i] - x[j]) <= 2 * r) {
                double y_cur = y_position(i, j);
                if (y_cur > y_max + eps) 
                    y_max = y_cur;
            }
        }
        y[i] = y_max;
    }
    for (int i = 0; i < n; i++) 
        printf("%.8lf ", y[i]);
    printf("\n");
}

