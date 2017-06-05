#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

int n, m, ult;
char t[20][N];
int l[20], r[20];
int me[20][3];

int dp(int fl, int side) {
    if (fl == ult) {
        if (!side) return r[fl];
        return (m + 2 - 1 - l[fl]);
    }
    if (me[fl][side] != -1) return me[fl][side];

    int ans = 0;
    if (!side) {
        ans = r[fl] + min(r[fl] + 1 + dp(fl - 1, 0), m + 2 - 1 - r[fl] + 1 + dp(fl - 1, 1));
    } else {
        ans += (m + 2 - 1 - l[fl]) + min(l[fl] + 1 + dp(fl - 1, 0), m + 2 - 1 - l[fl] + 1 + dp(fl - 1, 1));
    }

    return me[fl][side] = ans;
}

int main () {
    scanf(" %d %d", &n, &m);
    memset(me, -1, sizeof me);
    ult = n - 1;
    for (int i = 0; i < n; i++) {
        l[i] = m + 2 - 1;
        r[i] = 0;
        for (int j = 0; j < m + 2; j++) {
            scanf(" %c", &t[i][j]);
            if (t[i][j] == '1') {
                ult = min(ult, i);
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        }
    }

    printf("%d\n", dp(n - 1, 0));
}

