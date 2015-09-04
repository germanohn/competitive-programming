#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1010

using namespace std;
 
int c, f, n, d, comp[55], desc[55], memo[205][MAX];

int dp (int i, int tot) {
    if (i == f || tot == 0) return memo[i][tot] = 0;
    if (memo[i][tot] != -1) return memo[i][tot];
    int r1, r2;
    r1 = dp (i + 1, tot);
    if (comp[i] <= tot) {
        r2 = desc[i] + dp (i + 1, tot - comp[i]);
        return memo[i][tot] = max (r1, r2); 
    }
    return memo[i][tot] = r1;
}

int main () {
    int cont = 1;
    while (scanf ("%d %d", &c, &f) && c != 0 && f != 0) {
        memset (memo, -1, sizeof (memo));
        for (int i = 0; i < f; i++)
            scanf ("%d %d", &comp[i], &desc[i]);
        printf ("Teste %d\n%d\n\n", cont++, dp (0, c));
    }     
}
