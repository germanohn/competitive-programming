#include <bits/stdc++.h>

using namespace std;

int n, k, v[20], me[35][20];

int pd (int n, int k) {
    if (n < k) { 
        return 0;
    }
    if (n == k || k == 0) {
        return 1;
    }
    int &m = me[n][k];
    if (m != -1) {
        return m;
    }
    return m = pd (n-1, k-1) + pd (n-1, k);
}

int main () {
    /*while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }
    }*/
    scanf ("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            me[i][j] = -1;
        }
    }
    printf ("%d\n", pd (n, k));
}
