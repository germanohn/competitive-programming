#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2005;

int t;
char A[N], B[N];
int me[N][N];

int dp(int i, int j) {
    if (A[i] == 0 || B[j] == 0) return (A[i] == B[j]) ? 0 : N;
    if (me[i][j] != -1) return me[i][j];

    int ans;
    if (A[i] == B[j]) {
        ans = dp(i + 1, j + 1);
    } else {
        ans = min(1 + dp(i + 1, j + 1), min(1 + dp(i + 1, j), 1 + dp(i, j + 1)));
    }

    return me[i][j] = ans;
}

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %s %s", A, B);
        memset(me, -1, sizeof me);

        printf("%d\n", dp(0, 0));
    }
}

