#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
const int inf = 1e9 + 1e5 + 5;

int n, w, m;
ll v[N], lose[N];

bool ok(int h) {
    for (int i = 0; i < n; i++) 
        lose[i] = 0;
    ll aux = 0, has = 0;
    for (int i = 0; i < n; i++) {
        has -= lose[i];
        if (has < 0) has = 0;
        if (h > has + v[i]) {
            ll up = h - (has + v[i]);
            aux += up, has += up, lose[i + w] += up;
        }
    }

    if (aux <= m) return true;
    return false;
}

int main () {
    scanf(" %d %d %d", &n, &m, &w);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i]);
    }

    int lo = 1, hi = inf;
    while (lo != hi) {
        int mid = (lo + hi + 1) / 2;
        if (ok(mid))
            lo = mid;
        else 
            hi = mid - 1;
    }

    printf("%d\n", lo);
}

