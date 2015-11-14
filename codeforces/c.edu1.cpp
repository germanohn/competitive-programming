#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;

struct tipo {
    int x, y;
    double ang;
};

tipo p[MAX], tmp;

int n, x, y;
double mi = -2;

bool comp (tipo a, tipo b) {
    return a.ang < b.ang;
}

bool angulo (tipo a, tipo b, int op) {
    double ta, tb, ang;
    ta = a.x*a.x + a.y*a.y;
    tb = b.x*b.x + b.y*b.y;
    ang = ((a.x*b.x + a.y*b.y)/(sqrt (ta*tb)));
    //printf ("ang %lf\n", ang);
    if (op) {
        if (ang > mi) {
        mi = ang;
        return 1;
        }
        else return 0;
    }
    else return ang;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &p[i].x, &p[i].y);
        int a = p[i].x, b = p[i].y;
        tmp.x = 1, tmp.y = 0;
        p[i].ang = angulo (p[i], tmp, 0); 
    }
    sort (p, p+n, comp);
    /*printf ("\n");
    for (int i = 0; i < n; i++) {
        printf ("%d %d\n", p[i].x, p[i].y);
    }*/
    int e, d;
    for (int i = 0; i < n-1; i++) {
        if (angulo (p[i+1], p[i], 1)) {
            e = i+1, d = i+2;
        }
    }
    printf ("%d %d\n", e, d); 
}
