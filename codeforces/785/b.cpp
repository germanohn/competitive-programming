#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
const int inf = 1e9 + 5;

int n, m;
pii c[N], p[N];

int main () {
    scanf(" %d", &n);
    int min_c, max_c;
    min_c = inf, max_c = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        max_c = max(max_c, l);
        min_c = min(min_c, r);
    }

    scanf(" %d", &m);
    int min_p, max_p;
    min_p = inf, max_p = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        max_p = max(max_p, l);
        min_p = min(min_p, r);
    }

    int ans = max(0, max(max_c - min_p, max_p - min_c));
    printf("%d\n", ans);
}

