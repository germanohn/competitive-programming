#include <cstdio>
#include <algorithm>

using namespace std;

int n, memo[105][105], ma[105][105];

int pd (int i, int j ) {
    if (i == n) return 0;
    int &m = memo[i][j];
    if (m != -1) return m;
    return m = ma[i][j] + max (pd (i+1, j), pd (i+1, j+1));
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf ("%d", &ma[i][j]);
            memo[i][j] = -1;
        }
    }
    printf ("%d\n", pd (0, 0));
}
