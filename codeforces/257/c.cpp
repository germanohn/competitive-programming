#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int N = 1e5 + 5;
const double eps = 1e-7;
const double pi = acos(-1);

int n;
double ang[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        ang[i] = atan2(y, x);
    }
    sort(ang, ang + n);

    double ans = ang[n - 1] - ang[0];

    for (int i = 1; i < n; i++) 
        ans = min(ans, (2 * pi) - (ang[i] - ang[i - 1]));

    printf("%lf\n", (180. * ans) / pi);
}

