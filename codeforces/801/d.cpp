#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const double inf = 1e15;
const double eps = 1e-9;

struct point {
    double x, y;

    point() {}
    point(double x, double y) : x(x), y(y) {}

    point operator- (point a) {
        return point(x - a.x, y - a.y);
    }

    point operator+ (point a) {
        return point(x + a.x, y + a.y);
    }

    double cross(point a) {
        return x * a.y - y * a.x;
    }

    double dist(point a) {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};

int n;
point p[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %lf %lf", &p[i].x, &p[i].y);
    }

    double D = inf;
    for (int i = 0; i < n; i++) {
        point AB = point(p[i] - p[(i + 2) % n]);
        point AC = point(p[i] - p[(i + 1) % n]);
        double aux = fabs(AB.cross(AC)) / (2. * p[i].dist(p[(i + 2) % n]));
        if (aux - D < eps)
            D = aux;
    }
    
    printf("%.8lf\n", D);
}

