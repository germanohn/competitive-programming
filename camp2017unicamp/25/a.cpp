#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = acos(-1);

const int N = 1234;

int n, r, c[N];

class Point {
public:
    Point () {}
    Point (double x, double y) : x(x), y(y) {}
    double x, y;
    double operator* (const Point &o) const {
        return x * o.x + y * o.y;
    }
    double operator^ (const Point &o) const {
        return x * o.y - y * o.x;
    }
    double dist2() const {
        return *this * *this;
    }
    double dist() const {
        return sqrt(dist2());
    }
    Point operator- (const Point &o) const {
        return Point(x - o.x, y - o.y);
    }
    Point operator+ (const Point &o) const {
        return Point(x + o.x, y + o.y);
    }
    Point operator* (const double lambda) const {
        return Point(x * lambda, y * lambda);
    }
};

double get_intersect(int i, int j) {
    double rr = r * r;
    if(abs(c[i]-c[j]) >= 2*r) return pi * rr;
    Point a = Point(c[i], 0);
    Point ah = Point(c[j]-c[i], 0) * .5;
    Point h = ah + a;
    Point p = Point(0, 1) * sqrt(rr - ah.dist2()) + h;
    Point q = Point(0, -1) * sqrt(rr - ah.dist2()) + h;
    Point ap = p-a;
    double ang = 2 * atan2(ap.y, ap.x);
    double inter = 2 * (ang * rr * .5 - ((p-h).dist() * ah.dist()));
    return pi * rr - inter;
}

int main () {
    scanf("%d %d",&n, &r);
    for(int i = 0; i < n; i++)
        scanf("%d", c+i);

    sort(c, c+n);
    double ans = pi * r * r;
    for(int i = 1; i < n; i++) {
        ans += get_intersect(i-1, i);        
    }
    printf("%.20lf\n", ans);
}

