#include <bits/stdc++.h>
using namespace std;

struct shark {
    int l, r, q;
};

shark s[100005];
int n, p;
double ans = 0;

int main () {
    scanf ("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &s[i].l, &s[i].r);
        s[i].q = s[i].r/p - (s[i].l - 1)/p;
        //printf ("%d %d %d\n", s[i].l, s[i].r, s[i].q);
    }
    double a, b;
    for (int i = 0; i < n; i++) {
        //printf ("ans %lf\n", ans);
        int res = (i+1)%n;
        //printf ("res %d numerador %d\n", res, s[res].r-s[res].l+1-s[res].q);
        a = ((double) (s[i].r-s[i].l+1-s[i].q)/(s[i].r-s[i].l+1)); 
        b = ((double) (s[res].r-s[res].l+1-s[res].q)/(s[res].r-s[res].l+1));
        //printf ("a %lf b %lf\n", a, b);
        ans += 1 - (a*b);
    }
    printf ("%lf\n", ans*2000);
}   
