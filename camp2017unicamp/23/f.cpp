#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-9;

struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator+ (const point &a) const {
        return point(x + a.x, y + a.y);
    }
    point operator- (const point &a) const {
        return point(x - a.x, y - a.y);
    }
    point operator* (double a) const {
        return point(a * x, a * y);
    }
    bool operator< (const point &a) const {
        if (fabs(x - a.x) < eps) return (y < a.y + eps);
        return (x < a.x + eps);
    }
    point proj (const point &a) const {
        double lambda = (*this * a) / a.dist2();
        return a * lambda; 
    }
    double operator* (const point &a) const {
        return x * a.x + y * a.y;
    }
    double operator^ (const point &a) const {
        return x * a.y - y * a.x;
    }
    double dist() const {
        return sqrt(dist2());
    }
    double dist2() const {
        return x * x + y * y;
    }
};

double qd(double a) {
    return a * a;
}

point read() {
    double x, y;
    scanf(" %lf %lf", &x, &y);
    return point(x, y);
}

int main () {
    int t;
    scanf(" %d", &t);
    while (t--) {
        double lm, lg;
        scanf(" %lf %lf", &lm, &lg);
        point a, b, c;
        a = read();
        b = read();
        c = read();
        bool ans = false;
        if (fabs((b - a) ^ (c - a)) < eps) {
            double mx = max((b - a).dist2(), max((c - a).dist2(), (b - c).dist2()));
            if (mx <= max(4 * qd(lg), qd(lm)) + eps)
                ans = true;
            else 
                ans = false;
        } else {
            vector<point> v;
            v.pb(a), v.pb(b), v.pb(c);
            sort(v.begin(), v.end());
            do {
                // dois pontos juntos: A e B. C ponto separado
                a = v[0], b = v[1], c = v[2];
                
                // A e B nas guardas
                point ab = b - a;
                point ac = c - a;
                point x = ac.proj(ab) + a;
                point ax = x - a;
                point bx = x - b;
                point cx = x - c;
                if (ax.dist2() <= qd(lg) + eps && bx.dist2() <= qd(lg) + eps &&
                    cx.dist2() <= qd(lm) + eps)
                    ans = true;

                if (cx.dist2() <= qd(lg) + eps && ax.dist2() <= qd(lm) + eps &&
                    bx.dist2() <= qd(lm) + eps && ax * bx > -eps)
                    ans = true;
            } while (!ans && next_permutation(v.begin(), v.end()));
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}

