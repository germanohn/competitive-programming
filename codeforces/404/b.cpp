#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double a, d;
int n;

int main () {
    scanf(" %lf %lf %d", &a, &d, &n);
    double cur = 0;
    for (int i = 0; i < n; i++) {
        cur += d;
        cur -= floor(cur / (4 * a)) * 4 * a;
        if (cur <= a) 
            printf("%lf %lf\n", cur, 0.);
        else if (cur <= 2 * a) 
            printf("%lf %lf\n", a, cur - a);
        else if (cur <= 3 * a)
            printf("%lf %lf\n", (3 * a) - cur, a);
        else 
            printf("%lf %lf\n", 0., (4 * a) - cur);
    }
}

