#include <bits/stdc++.h>
using namespace std;

int acc[10005][2];
char A[105][10005];

int main () {
    int n, m;
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf (" %s", A[i]+1);
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (A[i][j] == 'W') acc[j][0]++;
            else if (A[i][j] == 'E') acc[j][1]++;
        }
    }
    acc[0][0] = acc[0][1] = 0;
    for (int i = 1; i <= n; i++) 
        acc[i][0] += acc[i-1][0], acc[i][1] += acc[i-1][1];
    int mi = INT_MAX, l, r, aux;
    for (int i = 0; i <= n; i++) {
        aux = acc[i][1] + acc[n][0] - acc[i][0];
        if (aux < mi) mi = aux, l = i, r = i+1;
    }
    printf ("%d %d\n", l, r);
}
