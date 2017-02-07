#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 402;
int n;
double x[N];
const double eps = 1e-9;
double novo[N];

double final(double d, double f) {
    double pos = f;
    double ffinal = 0;
    for(int i = 0; i < n; i++) {
        ffinal += fabs(x[i] - pos);
        pos += d;
    }
    return ffinal;
}

double calc(double f) {
    double l = -1e6, r = 1e6;
    int iter = 0;
    //printf("Para o ponto %lf\n", f);
    while(iter++ < 300) {
        //printf("Distancia %lf %lf\n", l, r);
        double t = fabs(r-l)/3.;
        double a = l + t;
        double b = l + 2.*t;
        if(final(a, f) < final(b, f) + eps) r = b;
        else l = a;
    }
    return l;
}

int main () {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lf", x+i);
    double l = -1e7, r = 1e7;
    int iter = 0;
    while(iter++ < 300) {
        double t = fabs(r-l)/3.;
        double a = l + t;
        double b = l + 2.*t;
        if(final(calc(a), a) < final(calc(b), b) + eps) r = b;
        else l = a;
    } 
    double d = calc(l);
    double res = 0;
    double pos = l;
    for(int i = 0; i < n; i++) {
        res += fabs(x[i] - pos);       
        novo[i] = pos;
        pos += d;
    } 
    printf("%.20lf\n", res);
    for(int i = 0; i < n; i++) printf("%.20lf ", novo[i]);
    putchar('\n');
}

