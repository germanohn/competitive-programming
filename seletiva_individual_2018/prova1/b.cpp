#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 5e4 + 4;

struct Point {
    ll x, y;

    Point() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    ll operator*(const Point &p) const {
        return x * p.y - y * p.x;
    }
};

typedef Point Vector;

Point p[N];
ll area[N];

int main() {
    int n, q;
    while (scanf(" %d %d", &n, &q)) {
        if (n == 0 && q == 0) 
            break;

        for (int i = 0; i < n; i++) 
            scanf(" %lld %lld", &p[i].x, &p[i].y);   

        area[0] = 0ll;
        area[1] = 0ll;
        for (int i = 2; i < n; i++) { 
            Vector va = p[i - 1] - p[0];
            Vector vb = p[i] - p[0];
            area[i] = llabs(va * vb) + area[i - 1];
        }

        for (int i = 0; i < q; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            Vector va = p[a] - p[0];
            Vector vb = p[b] - p[0];
            ll area1 = area[a] + (area[n - 1] - area[b]) + llabs(va * vb);
            ll min_area = min(area1, area[n - 1] - area1);
            if (min_area % 2 == 0) {
                printf("%lld.0\n", min_area / 2);
            } else {
                printf("%lld.5\n", min_area / 2);
            }
            if (i < q - 1) 
                printf("\n");
        }
    }
}

