#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, k;
pii v[N];

bool cmp(pii a, pii b) {
    return (a.ff - a.ss) < (b.ff - b.ss);
}

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i].ff);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i].ss);
    }

    sort(v, v + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < k) ans += v[i].ff;
        else if (i >= k && v[i].ff < v[i].ss) ans += v[i].ff;
        else ans += v[i].ss;
    }
    printf("%d\n", ans);
}

