#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 300005;

struct tii {
    l, r, c;
};

int n, k;
bool seen[MAX];
tii v[MAX];
set<tii> coupon;

bool cmp(tii a, tii b) {
    if (a.l < b.l) return true;
    else if (a.l == b.l) 
        return a.r < b.r;
    return false;
}

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i].l, &v[i].r);
        coupon.insert(pii(-v[i].l, v[i].r));
        v[i].c = i;
    }
    sort(v, v + n, cmp);
    for (int i = 0; i < n; i++) {
        set<tii>::iterator x = coupon.lower_bound(pii(-v[i].l, v[i].r));
    }
}

