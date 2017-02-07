#include <bits/stdc++.h>
#define r first
#define p second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 100005;

int n;
pll v[MAX];
multiset<pll> s;

int main () {
    freopen("pulp.in", "r", stdin);
    freopen("pulp.out", "w", stdout);
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %lld %lld", &v[i].r, &v[i].p);
    sort(v, v + n);
    int j = 1;
    pll now = v[0];
    ll at, ans;
    at = now.r, ans = 0;
    while (j < n) {
        ll fim = at + now.p;
        if (now.p != -1 && fim <= v[j].r) {
            ans += fim;
            if (fim == v[j].r) {
                s.insert(pll(v[j].p, v[j].r));
                j++;
            }
            if (s.begin() != s.end()) {
                pll a = *s.begin();
                now = pll(a.p, a.r);
                s.erase(s.begin());
            } else {
                now = pll(-1, -1);
            }
            at = fim;
        } else {
            s.insert(pll(v[j].p, v[j].r));
            if (now.p != -1) {
                now.p -= (v[j].r - at);
                s.insert(pll(now.p, now.r));
            }
            pll a = *s.begin();
            now = pll(a.p, a.r);
            s.erase(s.begin());
            at = v[j].r;
            j++;
        } 
    }

    if (now.p != -1) {
        ans += at + now.p;
        at += now.p;
    }
    //printf("at %d %d %d\n", at, now.r, now.p);
    while (!s.empty()) {
        pll a = *s.begin();
        now = pll(a.p, a.r);
        s.erase(s.begin());
        ans += at + now.p;
        at += now.p;
    }

    printf("%lld\n", ans);
}

