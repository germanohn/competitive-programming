#include <bits/stdc++.h>

using namespace std;

int n, m, tam, lon, memo[25][25], ind;
char dic[1005][25], pal[25];

int pd (int i, int j) {
    if (i == tam && j == lon)   
        return 0;
    
    if (i == tam) 
        return lon - j;
    if (j == lon) 
        return tam - i;  
    
    int &me = memo[i][j];
    if (me != -1) return me;

    int a = pd (i, j + 1) + 1;
    int b = pd (i + 1, j) + 1;
    int c = pd (i + 1, j + 1) + (pal[i] != dic[ind][j]);

    return me = min (a, min (b, c));

}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", dic[i]);
    for (int i = 0; i < m; i++) {
        
        scanf ("%s", pal);
        tam = strlen (pal);
        for (ind = 0; ind < n; ind++) {
            lon = strlen (dic[ind]);
            for (int k = 0; k < 25; k++) 
                for (int j = 0; j < 25; j++) 
                    memo[k][j] = -1;
            if (abs (tam - lon) <= 2) {
                int quant = pd (0, 0);
                if (quant <= 2) 
                    printf ("%s ", dic[ind]); 
            }
        }
      
        printf ("\n");       
        
    }
}
