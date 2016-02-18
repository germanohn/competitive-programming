#include <bits/stdc++.h>
using namespace std;

int me[55][55];
char s1[55], s2[55];

//recursivo
/*int dp (int a, int b) {
    if (a < 0 || b < 0) return 0;
    if (me[a][b] != -1) return me[a][b];
    if (s1[a] == s2[b]) 
        return me[a][b] = 1 + dp (a - 1, b - 1);
    dp (a - 1, b), dp (a, b - 1);
    return me[a][b] = 0;
}

int main () {
    while (scanf (" %[^\n]", s1) != EOF) {
        memset (me, -1, sizeof me);
        scanf (" %[^\n]", s2);
        int n, m;
        n = strlen (s1);
        m = strlen (s2);
        dp (n-1, m-1);
        int ma = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ma = max (ma, dp (i, j));
            }
        }
        printf ("%d\n", ma);
    }
}*/

//iterativo
int main () {
    while (scanf (" %[^\n]", s1) != EOF) {
        scanf (" %[^\n]", s2);
        memset (me, -1, sizeof me);
        int n, m, ma = INT_MIN;
        n = strlen (s1), m = strlen (s2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j]) {
                    if (i == 0 || j == 0) me[i][j] = 1;
                    else me[i][j] = 1 + me[i-1][j-1];
                } else 
                    me[i][j] = 0;
                ma = max (ma, me[i][j]);
            }
        }
        printf ("%d\n", ma);
    }
}
