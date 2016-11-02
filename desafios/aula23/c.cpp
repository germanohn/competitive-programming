#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 10005;
const int inf = 1e9 + 1;

int n;
int p[MAX];
pll pto1, pto2;
pll pto[MAX];

ll cross(pll a, pll b) {
    return ((a.x - pto1.x) * (b.y - pto1.y)) - ((a.y - pto1.y) * (b.x - pto1.x));
}

bool cmp(int a, int b) {
    if (cross(pto[a], pto[b]) < 0) return true;
    return false;
}

int main() {
    int pos;
    pto1.x = inf, pto1.y = inf;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        scanf(" %lld %lld", &pto[i].x, &pto[i].y);
        if (pto[i].x < pto1.x || (pto[i].x == pto1.x && pto[i].y < pto1.y))
            pto1.x = pto[i].x, pto1.y = pto[i].y, pos = i;    
    } 

    swap(p[0], p[pos]);
    pto1 = pto[p[0]];
    sort(p + 1, p + n, cmp);

    printf("%d %d\n", p[0] + 1, p[n/2] + 1);
}
