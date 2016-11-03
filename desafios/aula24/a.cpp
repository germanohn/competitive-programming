#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<double, double> pdd;

const int MAX = 105;
const double pi = acos(-1);

pdd v[MAX];

double dis(pdd a, pdd b) {
    return sqrt(((a.ff - b.ff) * (a.ff - b.ff) + ((a.ss - b.ss) * (a.ss - b.ss))));     
}

int main() {
    int n;
    double r;
    scanf(" %d %lf", &n, &r);

    for (int i = 0; i < n; i++) {
        scanf(" %lf %lf", &v[i].ff, &v[i].ss);
    }       

    double ans = 0;
    for (int i = 1; i < n; i++) 
        ans += dis(v[i - 1], v[i]);
    ans += dis(v[n - 1], v[0]);

    ans += (2*pi*r);
    printf("%.2lf\n", ans);
}
