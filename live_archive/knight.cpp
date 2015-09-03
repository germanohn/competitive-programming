/*0: safe, 1:Dama, 2:knight, 3:pawn, 4:not safe*/
#include <cstdio>
#include <algorithm>
#include <set>

#define MAX 1005
#define MAXN 105

using namespace std;

int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int qx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; 
int qy[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; 

int k, p, q, n, m, A[MAX][MAX], x, y;

int main () {
    int ord = 1;
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                A[i][j] = 0;
        scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &x, &y);    
            A[x][y] = 1;
        }
        scanf ("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf ("%d %d", &x, &y);    
            A[x][y] = 2;
        }
        scanf ("%d", &p);
        for (int i = 0; i < p; i++) {
            scanf ("%d %d", &x, &y);    
            A[x][y] = 3;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i][j] == 2) {
                    for (int l = 0; l < 8; l++) {
                        int x = i + kx[l];
                        int y = j + ky[l];  
                        if (x >= 1 && x <= n &&
                            y >= 1 && y <= m) {
                                if (A[x][y] == 0) 
                                    A[x][y] = 4;             
                        }
                    }
                }
                if (A[i][j] == 1) {
                    for (int z = 0; z < 8; z++) {
                        int w = 1;
                        while (1) {
                            int x = i + qx[z]*w;
                            int y = j + qy[z]*w;
                            if (x < 1 || x > n || y < 1 || y > m || A[x][y] == 1 || A[x][y] == 2 || A[x][y] == 3) 
                                break;
                            else
                                A[x][y] = 4;
                            w++;
                        }
                    }
                }
            }
        }
        int cont = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                if (A[i][j] == 0)
                    cont++;   
        } 
        printf ("Board %d has %d safe squares.\n", ord, cont);   
        ord++;
    }
}    
    
