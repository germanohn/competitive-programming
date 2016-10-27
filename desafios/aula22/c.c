#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6105

char s[MAX];
int me[MAX][MAX];

int dp(int i, int j) {
    if (i == j || i > j) return 0;

    if (me[i][j] != -1) return me[i][j];

    int ans;
    if (s[i] == s[j]) ans = dp(i + 1, j - 1);
    else {
        int a, b;
        a = dp(i + 1, j);
        b = dp(i, j - 1);
        if (a < b) ans = 1 + a;
        else ans = 1 + b;
    }

    return me[i][j] = ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    while(t--) {
        scanf(" %s", s);
        memset(me, -1, sizeof(me));
        int len = strlen(s);
        
        printf("%d\n", dp(0, len - 1));
    }
}
