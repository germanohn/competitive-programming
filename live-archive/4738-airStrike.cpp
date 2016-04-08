#include <bits/stdc++.h>
#define dis first
#define id second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n;
double d2[MAX];
double a, b, x, y, area;
double pi = 3.141;
pair<double, int> d1[MAX];

double dist (double c, double d, double e, double f) {
    return (c-d)*(c-d) + (e-f)*(e-f);
}

int main () {
    int t = 1;
    while (scanf ("%d", &n) && n != 0) {
        scanf ("%lf %lf %lf %lf %lf", &a, &b, &x, &y, &area);
        double u, v;
        for (int i = 0; i < n; i++) {
            scanf ("%lf %lf", &u, &v);
            d1[i].dis = dist (a, u, b, v);
            d1[i].id = i;
            d2[i] = dist (x, u, y, v);
        }
        sort (d1, d1+n);
        int p1 = 0; 
        for (int i = 0; i < n; i++) {
            if (d1[i].dis*pi > area) {
                p1 = i;
                break;
            } else 
                p1++;
        }
        double free;
        int ans = INT_MAX, q;
        while (p1 >= 0) {
            if (p1 > 0)
                free = area - d1[p1-1].dis*pi;
            else 
                free = area;
            q = 0;
            for (int j = p1; j < n; j++) {
                if (d2[d1[j].id]*pi <= free) 
                    q++;
            }
            ans = min (ans, n-p1-q);
            p1--;
        }
        printf ("%d. %d\n", t++, ans);
    }
}





