#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int inf = 1e9;

int x, y, z;
int me[N][2];

int dp(int len, bool has_egg) {
    if (len == 1) return has_egg ? -x / 2 : 0;
    int &m = me[len][has_egg];
    if (m != -1) return m;

    m = inf;
    for (int j = 1; j < len; j++) 
        m = min(m, max(dp(j, false), dp(len - j, true)));           
    if (has_egg) m += z;
    else m += x + y;

    return m;
}

int main() {
    int t;
    scanf(" %d", &t);
    for (int i = 1; i <= t; i++) {
        memset(me, -1, sizeof me);
        int n;
        scanf(" %d %d %d %d", &n, &x, &y, &z);
        printf("Case %d: %d\n", i, dp(n, 0));
    }
}

