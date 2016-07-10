#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MAX = 50005;

int n;
pdd pto[MAX];

double maxi (double x) {
    double maxi = -1;
    for (int i = 0; i < n; i++) 
        maxi = max (maxi, (pto[i].ff-x)*(pto[i].ff-x) + pto[i].ss*pto[i].ss);
    return maxi;
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) 
            scanf ("%lf %lf", &pto[i].ff, &pto[i].ss);
        sort (pto, pto+n);
        double l = pto[0].ff, r = pto[n-1].ff;
        double lt, rt, max_lt, max_rt;
        int cont = 0;
        while (cont < 300) {
            lt = l + (r-l)/3, rt = r - (r-l)/3;
            max_lt = maxi (lt), max_rt = maxi (rt);
            if (max_lt < max_rt)
                r = rt;
            else 
                l = lt;
            cont++;
        }
        double x, time;
        x = (l+r)/2;
        time = sqrt (maxi (x));
        printf ("%lf %lf\n", x, time); 
    }
}

