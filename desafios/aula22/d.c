#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX = 3005;

int n, m;
char grid[MAX][MAX];

int main() {
    scanf(" %d %d", &n, &m);
    memset(me, -1, sizeof(me));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    printf("%d\n", dp(0, 0));
}
