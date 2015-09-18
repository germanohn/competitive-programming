#include <bits/stdc++.h>

using namespace std;

int n, m, tam, lon, memo[25][25], ind;
char dic[1005][25], pal[25];

int pd (int i, int j) {
    if (i == tam && j == lon) return 0;
    if (i == tam) return j - lon;
    if (j == lon) return i - tam;
    int &m = memo[i][j];
    if (m != -1) return m;
    if (pal[i] == dic[ind][j])
        return m = pd (i + 1, j + 1);
    return m = min (pd (i, j + 1) + 1, min (pd (i + 1, j) + 1, pd (i + 1, j + 1) + 1));
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", dic[i]);
    for (int i = 0; i < m; i++) {
        for (int i = 0; i < 25; i++) 
            for (int j = 0; j < 25; j++) 
                memo[i][j] = -1;
        scanf ("%s", pal);
        bool f = false;
        int tam = strlen (pal);
        for (ind = 0; ind < n; ind++) {
            lon = strlen (dic[ind]);
            if (abs (tam - lon) <= 2) 
                if (pd (0, 0) <= 2) {
                    printf ("%s ", dic[ind]);
                    f = true;
                }
        }
        if (!f) printf ("\n");
        printf ("\n");       
        
    }
}
