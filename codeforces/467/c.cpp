#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5005;
const ll inf = 1e14;

int n, m, k;
ll acc[MAX];
ll me[MAX][MAX];

ll dp(int i, int left) {
    if (left == 0) return 0;
    if (n - i + 1 < left * m) return -inf;
    if (me[i][left] != -1) return me[i][left];
    return me[i][left] = max(acc[i + m - 1] - acc[i - 1] + dp(i + m, left - 1), 
                             dp(i + 1, left));
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &acc[i + 1]);
        acc[i + 1] += acc[i];
    }
    printf("%lld\n", dp(1, k));
}

