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

int k, p, q, n, m, A[MAX][MAX];

int main () {
    int ord = 1;
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        pair<int, int> queen[MAXN];
        pair<int, int> knight[MAXN];
        pair<int, int> pawn[MAXN];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                A[i][j] = 0;
        scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &queen[i].first, &queen[i].second);    
            A[queen[i].first][queen[i].second] = 1;
        }
        scanf ("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf ("%d %d", &knight[i].first, &knight[i].second);    
            A[knight[i].first][knight[i].second] = 2;
        }
        scanf ("%d", &p);
        for (int i = 0; i < p; i++) {
            scanf ("%d %d", &pawn[i].first, &pawn[i].second);    
            A[pawn[i].first][pawn[i].second] = 3;
        }
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < 8; i++) {
                int x = knight[j].first + kx[i];
                int y = knight[j].second + ky[i];  
                if (x >= 1 && x <= n &&
                    y >= 1 && y <= m) {
                        if (A[x][y] == 0) 
                            A[x][y] = 4;             
                }
            }
        }
        
        for (int j = 1; j <= q; j++) {
            set<int> npode;
            int cont = 1;
            while (npode.size () < 8) {
                for (int i = 0; i < 8; i++) {
                    int x = queen[j-1].first + qx[i]*cont;
                    int y = queen[j-1].second + qy[i]*cont;
             
                    if (x >= 1 && x <= n &&
                        y >= 1 && y <= m && npode.find(i) == npode.end ()) {
                        if (A[x][y] == 0) 
                            A[x][y] = 6;
                        else if (A[x][y] == 1 || A[x][y] == 2 || A[x][y] == 3) {
                            npode.insert (i);
                        }
            
                    }
                    else {
                        npode.insert (i);
                    }
                }
                cont++;   
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
    
