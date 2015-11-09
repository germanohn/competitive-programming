#include <bits/stdc++.h>
using namespace std;

int n, m, cont;
int A[105][210];

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2*m; j++) {
            scanf ("%d", &A[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= 2*m; j += 2) {
            if (A[i][j] == 1 || A[i][j-1] == 1)
                cont++;
        }
    }
    printf ("%d\n", cont);
}
