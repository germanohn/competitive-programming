#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1010

using namespace std;

int mem[MAX][MAX];
int row[MAX];

int pd (int i, int j) {
    if (i > j) return 0;
    if (mem[i][j] != -1) return mem[i][j];
    int ini, fim;
    if (row[i+1] >= row[j]) 
        ini = row[i] - row[i+1] + pd (i + 2, j); 
    else 
        ini = row[i] - row[j] + pd (i + 1, j - 1);
  
    if (row[i] >= row[j-1]) 
        fim = row[j] - row[i] + pd (i + 1, j - 1); 
    else 
        fim = row[j] - row[j-1] + pd (i, j - 2);
    
    mem[i][j] = max(ini, fim);
    return mem[i][j];
}

int main () {
    int n, m = 1;
    while (scanf ("%d", &n) && n != 0) {
        memset (mem, -1, sizeof mem);
        for (int i = 0; i < n; i++) 
            scanf ("%d", &row[i]);
        printf ("In game %d, the greedy strategy might lose by as many as %d points.\n", m, pd (0, n-1));
        m++;
    }
} 
