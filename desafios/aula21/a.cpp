#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 5005;

char v[MAX];
ll me[MAX][3], len;

ll dp(int i, bool f) {
    if (i == len) {
        if (!f) return 1;
        else return 0;
    }
    if (me[i][f] != -1) return me[i][f];

    ll ans = 0;
    if (f) {
        if (v[i - 1] == '1') ans += dp(i + 1, false);
        else  if (v[i - 1] == '2' && v[i] <= '6') ans += dp (i + 1, false);
    } else {
        if (v[i] != '0') ans += dp(i + 1, false) + dp(i + 1, true);
    }

    return me[i][f] = ans;
}

int main() {
    while(scanf(" %s", v)) {
        len = strlen(v);
        memset(me, -1, sizeof me);
        if (len == 1 && v[0] == '0') break;
        printf("%lld\n", dp(0, false));
    }
}
