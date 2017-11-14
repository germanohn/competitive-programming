#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;
const double eps = 1e-8;

struct Point {
    // Vpriables
    double x, y;

    // Constructors
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    // Operators
    Point operator+ (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator- (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    Point operator* (double k) const {
        return Point(k * x, k * y);
    }
    Point operator* (const Point &p) const {
        return Point(x * p.x, y * p.y);
    }
    double operator^ (const Point &p) const {
        return x * p.y - y * p.x; 
    }
    bool operator< (const Point &p) const {
        if (fabs(x - p.x) < eps) return (y < p.y + eps);
        return (x < p.x + eps);
    }

    // Functions
    double norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    Point rotate(double alpha) {
        return Point(x * cos(alpha) - y * sin(alpha), 
                     x * sin(alpha) + y * cos(alpha));
    }
};

using Vector = Point;

Vector operator/ (const Vector &v, double d) {
    return Vector(v.x / d, v.y / d);
}

int t, n;
double s[N];
Point p[N]; 

bool achieve(Point q, double tmp) {
    for (int i = 0; i < n; i++) {
        Vector vd = q - p[i];
        double d = vd.norm();

        if (d - s[i] * tmp > eps)
            return false;
    }
    return true;
}

bool inter_empty(double tmp) {
    bool ok = false;
    // centros
    for (int i = 0; !ok && i < n; i++) 
        if (achieve(p[i], tmp)) ok = true;

    // intersecções dois a dois
    for (int i = 0; !ok && i < n; i++) {
        for (int j = 0; !ok && j < n; j++) {
            if (i == j) continue;

            double r1 = tmp * s[i];
            double r2 = tmp * s[j];
            double R = max(r1, r2);
            double r = min(r1, r2);

            Vector vd = p[j] - p[i];
            double d = vd.norm();

            if (r1 + r2 - d > eps && d + r - R > eps) {
                double alpha = acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));

                Vector vr = vd / d * r1;

                Point inter = p[i] + vr.rotate(alpha);
                if (achieve(inter, tmp)) ok = true;
                inter = p[i] + vr.rotate(-alpha);
                if (!ok && achieve(inter, tmp)) ok = true;
            }
        }
    }

    return ok;
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) 
            scanf(" %lf %lf %lf", &p[i].x, &p[i].y, &s[i]);

        int cont = 0;
        double lo = 0., hi = 1e6;
        while (cont < 150) {
            double mid = (lo + hi) / 2;
            if (!inter_empty(mid))
                lo = mid;
            else 
                hi = mid;
            cont++;
        }   

        printf("%lf\n", lo);
    }
}

