#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#define MAX 310

using namespace std;

int v, p, vil[MAX], memo[MAX][35], m[MAX][MAX];

int pd2 (int x, int y) {
    if (m[x][y] != -1) return m[x][y];
    int sum = 0;
    for (int i = x + 1; i < y; i++) 
        sum += min (abs (vil[i] - vil[y]), abs (vil[i] - vil[x]));
    return m[x][y] = sum;
}    

int pd (int i, int post) {
    if (post == 0) {
        int soma = 0;
        for (int j = i; j < v; j++) 
            soma += vil[j] - vil[i];
        return memo[i][post] = soma;
    } 
    if (i == v-1)
        return 123456;
    if (memo[i][post] != -1) return memo[i][post];
    int sum, ans = INT_MAX;
    for (int k = i + 1; k < v; k++) {
        sum = pd2 (i, k); 
        ans = min (ans, sum + pd (k, post - 1));
    }
    return memo[i][post] = ans;
}

int main () {
    memset (m, -1, sizeof (m));
    memset (memo, -1, sizeof (memo));
    int mini = INT_MAX;
    scanf ("%d %d", &v, &p);
    for (int i = 0; i < v; i++) 
        scanf ("%d", &vil[i]);
    for (int i = 0; i < v; i++) {
        int soma = 0;
        for (int j = 0; j < i; j++) 
            soma += vil[i] - vil[j];
        soma = soma + pd (i, p - 1);
        if (soma < mini) mini = soma; 
        
    }
    printf ("%d\n", mini);    
}
