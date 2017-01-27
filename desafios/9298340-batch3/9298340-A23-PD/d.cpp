#include<bits/stdc++.h>
using namespace std;

const int MAX = 105;
const double eps = 1e-9;

struct point {
    double x, y;

    point() {}
    point(double x, double y) : x(x), y(y) {}

    point operator - () {
        return point(-x, -y);
    }

    point operator + (point p) {
        return point(x + p.x, y + p.y);    
    }

    point operator * (double a) {
        return point(a * x, a * y);
    }

    void rotate(double theta) {
        double a = x, b = y;
        x = a * cos(theta) + b * sin(theta);
        y = -a * sin(theta) + b * cos(theta);
    }
};

int n, ans;
double R, r, raio;
point pto[MAX];

double dis(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve(point inter) {
    int tmp = 0;
    for (int k = 0; k < n; k++) {
        if (dis(inter, pto[k]) <= raio*raio + eps)
            tmp++;
    }

    ans = max(ans, tmp);
}

int main() {
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) 
        scanf(" %lf %lf", &pto[i].x, &pto[i].y);    

    scanf(" %lf %lf", &R, &r);

    raio = R - r;
    if (raio < 0) {
        printf("0\n");
        return 0;
    }
    ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double d2 = dis(pto[i], pto[j]);
            if (d2 <= 4*raio*raio + eps) {
                double d = sqrt(d2);
                double theta = (acos((d/2)/raio));
                point dif = ((pto[j] + (-pto[i])) * (1/d)) * raio;
                dif.rotate(theta);
                point inter = pto[i] + dif;
                solve(inter);
                
                dif.rotate(-2*theta);
                inter = pto[i] + dif;
                solve(inter);
            }
        }
    }

    printf("%d\n", ans);
}
