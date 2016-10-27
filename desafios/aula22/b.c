#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 105

int h, w;
int me[MAX][MAX];
int grid[MAX][MAX];

int dp(int i, int j) {
    if (i == h - 1) return 0;
    if (me[i][j] != -1) return me[i][j];

    int ans = -1, a;
    if (j - 1 >= 0) {
        a = grid[i + 1][j - 1] + dp(i + 1, j - 1);
        if (a > ans) ans = a;
    }
    if (j + 1 <= w - 1) {
        a = grid[i + 1][j + 1] + dp(i + 1, j + 1);
        if (a > ans) ans = a;
    }
    a = grid[i + 1][j] + dp(i + 1, j);
    if (a > ans) ans = a;

    return me[i][j] = ans;
}

int main() {
    int t;
    scanf(" %d", &t);

    while(t--) {
        scanf(" %d %d", &h, &w);
        memset(me, -1, sizeof(me));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %d", &grid[i][j]);
            }
        }

        int ans = -1;
        for (int j = 0; j < w; j++) {
            int a = grid[0][j] + dp(0, j);
            if (a > ans) ans = a;
        }

        printf("%d\n", ans);
    }
}
