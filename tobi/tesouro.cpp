#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 10000
#define MAX 105 

using namespace std;

int x, y, n, v[MAX], memo[MAX][MAXN], tot;

int dp (int i, int soma) {
    if (soma == tot) return 1;
    if (i >= n || soma > tot) return 0;
    if (memo[i][soma] != -1) return memo[i][soma];
    
    if (dp (i + 1, soma + v[i])) 
           return memo[i][soma] = 1;

    if (dp (i + 1, soma)) 
           return memo[i][soma] = 1;
    return memo[i][soma] = 0; 
} 


int main () {
    int cont = 1, i, j;
    while (scanf ("%d %d %d", &x, &y, &n) && n != 0 && x != 0 && y != 0) {
        tot = 0;
        printf ("Teste %d\n", cont);
        for (i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            tot += v[i];
        }
        sort (v, v + n);  
        tot += x + y;
        for (i = 0; i < n; i++) {
            for (j = x; j < tot/2; j++) {
                memo[i][j] = -1;
            } 
        }
        if (tot % 2 != 0) {
            printf ("N\n\n");
        }
        else {        
            tot = tot/2;    
            if (dp (0, x)) printf ("S\n\n");
            else printf ("N\n\n");           
        }        
        cont++;
    }
}
