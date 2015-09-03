#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10500
#define MAX 110 

using namespace std;

int x, y, n, v[MAX], memo[MAX][MAXN], tot;

int dp (int i, int soma) {
    if (memo[i][soma] != -1) return memo[i][soma];
    if (i > n || soma > tot/2) return 0;
    if (soma == tot/2) return 1;
    
    return memo[i][soma] = dp (i + 1, soma + v[i]) + dp (i + 1, soma); 
} 


int main () {
    int cont = 1;
    while (scanf ("%d %d %d", &x, &y, &n) && n != 0 && x != 0 && y != 0) {
        tot = 0;
        printf ("Teste %d\n", cont);
        memset (memo, -1, sizeof (memo));
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            tot += v[i];
        }  
        tot += x + y;
        if (tot % 2 != 0) {
            printf ("N\n\n");
        }    
        else {        
            if (dp (0, x)) printf ("S\n\n");
            else printf ("N\n\n");           
        }        
        cont++;
    }
}
