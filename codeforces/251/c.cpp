#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, d;
int v[MAX];
int me[MAX][5];

ll comb(int a, int b) {
    if (a < b) return 0;
    if (b == 0 || a == b) return 1;
    if (me[a][b] != -1) return me[a][b];
    return me[a][b] = comb(a - 1, b - 1) + comb(a - 1, b);
}

int main () {
    scanf(" %d %d", &n, &d);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    ll ans = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(v, v + n, v[i] + d) - v;
        printf("pos %d\n", pos);
        ans += comb(pos - r, 3);
        printf("antes ans %d ", ans);
        if (r != i) 
            ans += (comb(pos - r, 2) * (r - i + 1)) + ((pos - r) * comb(r - i, 2)); 
        r = pos;
        printf("i %d ans %d\n", i, ans);
    }
    printf("%lld\n", ans);
}

