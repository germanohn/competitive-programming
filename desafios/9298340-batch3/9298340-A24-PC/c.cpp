#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 100005;
const int inf = 1e9 + 1;

int n;
int p[MAX];
pii v[MAX];
pii pto;

ll cross(pll a, pll b, pll c) {
    return ((a.ff - c.ff) * (b.ss - c.ss)) - ((a.ss - c.ss) * (b.ff - c.ff));
}

ll dis(pii a, pii b) {
    pll x = a, y = b;
    return ((x.ff - y.ff) * (x.ff - y.ff) + (x.ss - y.ss) * (x.ss - y.ss));
}

bool cmp(int a, int b) {
    if (cross(v[a], v[b], pto) < 0) return true;
    else if (cross(v[a], v[b], pto) == 0) {
        ll dis_a, dis_b;
        dis_a = dis(v[p[0]], v[a]);
        dis_b = dis(v[p[0]], v[b]);        
        if (dis_a < dis_b) return true;
    }
    return false;
}

bool is_triangle(int i) {
    if (cross(v[p[i]], v[p[(i + 1) % n]], v[p[(i + 2) % n]]) != 0) return true;
    return false;
}

int main() {
    scanf(" %d", &n);

    int pos_ff;
    pto.ff = inf, pto.ss = inf;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        scanf(" %d %d", &v[i].ff, &v[i].ss);        
        if (v[i].ff < pto.ff || (v[i].ff == pto.ff && v[i].ss < pto.ss)) {
            pto = v[i], pos_ff = i;
        }
    }

    swap(p[0], p[pos_ff]);
    sort(p + 1, p + n, cmp);

    for (int i = 0; i < n; i++) {
        if (is_triangle(i)) {
            printf("%d %d %d\n", p[i] + 1, p[(i + 1) % n] + 1, p[(i + 2) % n] + 1);
            return 0;
        }
    }


}
