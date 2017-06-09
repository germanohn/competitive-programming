#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e3 + 5;

struct point {
    int x, y;

    point() {}
    point(int x, int y) : x(x), y(y) {}

    point operator+ (const point &a) const {
        return point(x + a.x, y + a.y);
    }
    point operator- (const point &a) const {
        return point(x - a.x, y - a.y);
    }
    point operator* (const int a) const {
        return point(a * x, a * y);
    }
    point operator* (const point &a) const {
        return point(x * a.x, y * a.y);
    }
    int operator^ (const point &a) const {
        return (x * a.y) - (y * a.x);
    }

    int dist2() {
        return x * x + y * y;
    }
};

int t, n, sz;
int h[N];
point P[N];

int cross(point O, point A, point B) {
    return ((A - O) ^ (B - O));
}

int area(point O, point A, point B) {
    return abs(cross(O, A, B));
}

bool cmp(point A, point B) {
    int a = cross(P[0], A, B);
    if (a > 0) return true;
    if (a < 0) return false;
    return A.dist2() < B.dist2();
}

int ts(int l, int r, int a, int b) {
    while (r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (area(P[h[a]], P[h[b]], P[h[m1]]) < area(P[h[a]], P[h[b]], P[h[m2]])) 
            l = m1 + 1;
        else 
            r = m2 - 1;
    }    
    int ans = area(P[h[a]], P[h[b]], P[h[l]]); 
    int idx = l;
    for (int i = l + 1; i <= r; i++) {
        int cur = area(P[h[a]], P[h[b]], P[h[i]]);
        if (cur > ans) {
            ans = cur;
            idx = i;
        }
    }
    return idx;
}

int best_area(int i, int j) {
    int idx = ts(i, j, i, j);
    int opt1 = area(P[h[i]], P[h[j]], P[h[idx]]);
    idx = ts(j, i + sz, i, j);
    int opt2 = area(P[h[i]], P[h[j]], P[h[idx]]);
    return opt1 + opt2;
}

int min_element() {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (P[i].y < P[idx].y || 
           (P[i].y == P[idx].y && P[i].x < P[idx].x))
            idx = i;
    }
    return idx;
}

void convex_hull() {
    int idx = min_element();
    swap(P[0], P[idx]);
    sort(P + 1, P + n, cmp);

    sz = 0;
    h[sz++] = 0;
    h[sz++] = 1;
    for (int i = 2; i < n; i++) {
        while (sz >= 2 && cross(P[h[sz - 2]], P[h[sz - 1]], P[i]) <= 0)
            sz--;  
        h[sz++] = i;
    }
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) 
            scanf(" %d %d", &P[i].x, &P[i].y);

        convex_hull();
        for (int i = 0; i < sz; i++) 
            h[i + sz] = h[i];

        int ans = 0;
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 2; j < sz; j++) {
                ans = max(ans, best_area(i, j));  
            }
        }

        printf("%d%s\n", ans / 2, ans % 2 ? ".5" : "");
    }
}

