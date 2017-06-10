#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
const double pi = acos(-1);
const double eps = 1e-9;

struct point {
    ll x, y, r;

    point() {}

    double area() {
        return pi * r * r;
    }

    bool in(const point &a) const {
        ll dx = (x - a.x);
        ll dy = (y - a.y);
        if ((dx * dx) + (dy * dy) < a.r * a.r)
            return true;
        return false;
    }
};

int n;
double me[N][2][2];
bool seen[N];
point d[N];
vector<int> adj[N];

double signal(bool f) {
    if (!f) return 1;
    return -1;
}

double dp(int i, bool p1, bool p2) {
    if (i == n) return 0;
    seen[i] = true;
    double &memo = me[i][p1][p2];
    if (memo != -1) return memo;

    double aux1 = signal(p1) * d[i].area();
    double aux2 = signal(p2) * d[i].area();
    for (int v : adj[i]) {
        aux1 += dp(v, !p1, p2);
        aux2 += dp(v, p1, !p2);
    }

    return memo = max(aux1, aux2);
}

bool cmp(point a, point b) {
    return a.r < b.r;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                me[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        scanf(" %lld %lld %lld", &d[i].x, &d[i].y, &d[i].r);
    }

    sort(d, d + n, cmp); 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i].in(d[j])) {
                adj[j].pb(i);
                break;
            }
        }
    }


    double ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!seen[i]) {
            ans += dp(i, 0, 0);
        }
    }

    printf("%.10lf\n", ans);
}

