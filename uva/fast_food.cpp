#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
#define MAX 

using namespace std;

int n, k, rest[MAX], memo[MAX][MAX], m[MAX][MAX];

int pd2 (int ini, int fim) {
    if (m[ini][fim] != -1) return m[ini][fim];
    int dis_min = 0;
    for (int j = ini + 1; j < fim; j++) 
        dis_min += min (rest[j] - rest[ini], rest[fim] - rest[j]);
    return m[ini][fim] = dis_min;
}

int pd1 (int i, int depo) {
    if (depo == 0) {
        int sum = 0;
        for (int l = i + 1; l < n; i++) 
           sum += rest[l] - rest[i];
        return memo[i][depo] = sum; 
    }
    if (memo[i][depo] != -1) return memo[i][depo];
    if (i == n - 1) return 123456;
    int ans = INT_MAX;
    for (int j = i + 1; j < n; j++) 
        ans = min (ans, pd2 (i, j) + pd (j, depo - 1);
    return memo[i][depo] = mini;
}

int main () {
    memset (memo, -1, sizeof (memo));
    memset (m, -1, sizeof (m));
    int mini = INT_MAX;
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &rest[i]);
    for (int i = 0; i < n; i++) {
        int soma = 0;
        for (int j = 0; j < i; j++)
                soma += rest[i] - rest[j];
        soma += pd (i, k - 1);
        if (soma < mini) mini = soma;
    }
    printf ("%d\n", mini);
}
