#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m[1005][1005];
char c[1005];

int pd (int i, int j) {
    if (i > j) return 0;
    if (m[i][j] != -1) return m[i][j];
    if (c[i] == c[j]) {
        return m[i][j] =  max (pd (i + 1, j - 1), max (pd (i + 1, j), pd (i, j - 1)));
    else 
        return m[i][j] = max (pd (i + 1, j), pd (i, j - 1));
}

int main() {
    fgets(c, sizeof c, stdin);
    sscanf (c, "%d", &n);
    for (int i = 0; i < n; i++) {
      
        memset (m, -1, sizeof (m));
        fgets(c, sizeof c, stdin);
        int tam = strlen (c);   
        
        printf ("%d\n", pd (0, tam - 2));
    }
}
