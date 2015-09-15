#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 2010

using namespace std;

int n, v[MAX], memo[MAX][MAX];

int dp (int i, int j) {
    int dia = (n - j + i); 
    if (memo[i][j] != -1) return memo[i][j];
    if (i == j) return v[i]*dia;
    int a, b;
    a = v[i]*dia + dp (i + 1, j);
    b = v[j]*dia + dp (i, j - 1);
    return memo[i][j] = max (a, b);
}

int main () {
    memset (memo, -1, sizeof (memo));
    int dia;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    printf ("%d\n", dp (0, n - 1));
}            
            
