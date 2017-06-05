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
    int operator^ (const point &a) const {
        return (x * a.y) - (y * a.x);
    }
    bool operator< (const point &a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }

    int dist2() const {
        return x * x + y * y;
    }
};

int n, sz, colinear;
int h[N];
vector<point> P;
set<point> del;

bool cmp(point a, point b) {
    point OA = (a - P[0]);
    point OB = (b - P[0]);
    int cross = OA ^ OB;
    if (cross > 0) return true;
    if (cross < 0) return false;
    return OA.dist2() < OB.dist2();
}

int min_element() {
    int idx = 0;
    for (int i = 1; i < P.size(); i++) {
        if ((P[i].y < P[idx].y) ||
            (P[i].y == P[idx].y && P[i].x < P[idx].x))
            idx = i;
    }
    return idx;
}

int cross(point O, point A, point B) {
    return ((A - O) ^ (B - O));
}

void convex_hull() {
    int idx = min_element();
    swap(P[0], P[idx]);
    sort(P.begin() + 1, P.end(), cmp);

    del.clear();
    sz = 0;
    h[sz++] = 0;
    h[sz++] = 1;
    for (int i = 2; i < P.size(); i++) {
        while (sz >= 2 && cross(P[h[sz - 2]], P[h[sz - 1]], P[i]) < 0) {
            sz--;
        } 
        h[sz++] = i;
    }
}

void update_P() {
    colinear = 0; 
    for (int i = 2; i < sz; i++) {
        if (cross(P[h[i - 2]], P[h[i - 1]], P[i]) == 0) 
         colinear++;   
    }
    vector<point> aux;
    for (point X : P)
        aux.pb(X);
    del.clear();
    for (int i = 0; i < sz; i++) 
       del.insert(P[h[i]]);
    P.clear();
    for (int i = 0; i < aux.size(); i++) {
        if (del.find(aux[i]) == del.end())
            P.pb(aux[i]);
    } 
}

int count_layers() {
    int cont = 0;
    while (P.size() > 2) {
        convex_hull();
        update_P();
        if (sz - colinear > 2) cont++;
    }
    return cont;
}

int main () {
    while (scanf(" %d", &n) && n != 0) {
        P.clear();
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            P.pb(point(a, b));
        }
        if (count_layers() % 2 == 1) 
            printf("Take this onion to the lab!\n");
        else 
            printf("Do not take this onion to the lab!\n");
    }
}

