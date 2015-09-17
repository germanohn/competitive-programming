#include <cstdio>
#include <algorithm>
#define MAX 35

using namespace std;

int t, n;
long long int memo[MAX][MAX][15];
int x[6] = {0, -1, -1, 0, 1, 1};
int y[6] = {-1, -1, 0, 1, 1, 0};

long long int pd (int i, int j, int quant) {
    if (quant == 0) {
        if (i == 14 && j == 14) return 1;
        return 0;
    }
    long long int &m = memo[i][j][quant];
    if (m != -1) return m;
    long long int  walks = 0;
    for (int k = 0; k < 6; k++) 
        walks += pd (i + x[k], j + y[k], quant - 1);
    return m = walks;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < MAX; i++) 
            for (int j = 0; j < MAX; j++) 
                for (int l = 0; l <= n; l++) 
                    memo[i][j][l] = -1;
        printf ("%lld\n", pd (14, 14, n));
    }
}
