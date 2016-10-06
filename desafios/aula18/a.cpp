#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = 1e9;
const int MAX = 50004;

int n, m;
int v[MAX];
int me[105][MAX];

int dp (int i, int val) {
    if (i == n) {
        if (val == 0) return 0;
        else return inf;
    }
    if (val == 0) return 0;

    if (me[i][val] != -1) return me[i][val];

    int ans = dp (i + 1, val);
    if (val - v[i] >= 0)
        ans = min (ans , min (1 + dp (i, val - v[i]), 1 + dp (i + 1, val - v[i])));

    return me[i][val] = ans;
}

int main() {
    while (scanf (" %d", &m)) {
        if (m == 0) break;
        memset (me, -1, sizeof me);
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) 
            scanf ("%d", &v[i]);

        int ans = dp (0, m);
        if (ans >= inf) printf ("Impossivel\n");
        else printf ("%d\n", ans);
    }
}

