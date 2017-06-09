#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m;
ll a[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %lld", &a[i]);
    scanf(" %d", &m);
    ll ans = 0, highest = 0;
    for (int i = 0; i < m; i++) {
        ll w, h;
        scanf(" %lld %lld", &w, &h);
        w--;
        ans = max(a[w], highest);
        highest = max(a[w] + h, highest + h);
        printf("%lld\n", ans);
    }
}

