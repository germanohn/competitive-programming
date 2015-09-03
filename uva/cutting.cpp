#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
#define MAX 1005

using namespace std;

int memo[MAX][MAX], l, c, n, stick[55];

int dp (int i, int j) {
    if (j - i == 1) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int ans = INT_MAX;
    for (int k = i+1; k < j; k++) 
        ans = min (ans, dp (i , k) + dp (k, j) + stick[j] - stick[i]);
    return memo[i][j] = ans;
}

int main () {
    while (scanf ("%d", &l) && l != 0) {
        memset (memo, -1, sizeof (memo));
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf ("%d", &stick[i]);
        stick[0] = 0, stick[n+1] = l;
        printf ("The minimum cutting is %d.\n", dp (0, n+1));
    }

}

