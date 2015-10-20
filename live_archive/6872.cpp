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

int solve (int i, int f, int tmp) {
    int aux = 0;
    if (i == n-1)
    if (f < 0) {
        if (tmp > n-i)
           return pd (tmp, n-i);
        else 
           return ans += pd (n-i, tmp); 
    }
    if (i == n-1)
        return 1;

    for (int j = 0; j < v[i]; j++) {
        aux += solve (i+1, -1, tmp-j);
    }
    printf ("i %d aux %d\n", i, aux);
    return solve (i+1, 1, tmp-v[i]) + aux;
}

int main () {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            me[i][j] = -1;
        }
    }
    while (scanf ("%d", &n) && n != 0) {
        ans = 0, tot = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            tot += v[i];
        }
        for (int soma = 0; soma < tot; soma++) {
            ans += soma + 1;
        } 
        ans += solve (0, 1, tot);   
        printf ("%d\n", ans); 
    }
}
