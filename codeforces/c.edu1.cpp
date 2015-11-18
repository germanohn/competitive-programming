#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

struct tipo {
    int x, y;
    int pos;
};

tipo p[MAX];

int n;
long double PI = 3.14159265359;

long double ang (tipo a) {
    long double x = atan2 (a.y, a.x);
    if (x < 0.0) return x + 2*PI;
    return x;
}

bool comp (tipo a, tipo b) {
    return ang (a) < ang (b);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &p[i].x, &p[i].y);
        p[i].pos = i+1;
    }
    sort (p, p+n, comp);
    int e, d;
    long double ans = 100;
    for (int i = 0; i < n-1; i++) {
        long double dif = ang (p[i+1]) - ang (p[i]);
        dif = min (dif, 2*PI-dif);
        if (dif < ans) {
            e = p[i].pos, d = p[i+1].pos;
            ans = dif;
        }
    }

    long double dif = ang (p[n-1]) - ang (p[0]);
    dif = min (dif, 2*PI-dif);
    if (dif < ans) {
        e = p[n-1].pos, d = p[0].pos;
    }
    
    printf ("%d %d\n", e, d); 
}
