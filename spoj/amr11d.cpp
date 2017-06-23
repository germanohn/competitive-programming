#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 52;
const int inf = 1e4;

int t, n;
int v[N];
int me[N][N][1300];

int dp(int i, int ult, int acc) {
    if (i == n) 
        return (acc == (n * (n - 1) / 2)) ? 0 : inf;
    if (me[i][ult][acc] != -1) 
        return me[i][ult][acc];

    int ans = inf;
    for (int cur = ult; cur <= n - 1; cur++) {
        if ((cur + acc) >= ((i + 1) * i) / 2)
            ans = min(ans, abs(cur - v[i]) + dp(i + 1, cur, acc + cur));
    }
    return me[i][ult][acc] = ans;
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        memset(me, -1, sizeof me);
        scanf(" %d", &n);
        for (int i = 0; i < n; i++)
            scanf(" %d", &v[i]);
        sort(v, v + n);

        printf("%d\n", dp(0, 0, 0));
    }
}

