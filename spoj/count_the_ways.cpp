#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 300010

using namespace std;

int n, v[5] = {1, 5, 10, 25, 50};
long long int memo[5][MAX];

long long int dp (int moeda, long long int quant) {
    if (moeda == 5 || quant < 0) return 0;
    if (memo[moeda][quant] != -1) return memo[moeda][quant];
    if (quant == 0) return 1;
    return memo[moeda][quant] = dp (moeda, quant - v[moeda]) + dp (moeda + 1, quant);
}

int main () {
    memset (memo, -1, sizeof (memo));
    while (scanf ("%d", &n) != EOF) {
        if (dp (0, n) == 1)
            printf ("There is only 1 way to produce %d cents change.\n", n);
        else
            printf ("There are %lld ways to produce %d cents change.\n", dp (0, n), n);
    }
}
