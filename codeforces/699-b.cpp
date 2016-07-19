#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 1005;

int n, m;
char grid[MAX][MAX];
int qRow[MAX];

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf (" %c", &grid[i][j]);
        }
    }
    bool appear = false;
    bool ans = true;
    int linha = -1, coluna = -1, aux, cont = 0;
    for (int i = 0; ans && i < n; i++) {
        int q = 0;
        for (int j = 0; ans && j < m; j++) {
            if (grid[i][j] == '*') {
                q++;
                if (q >= 2) {
                    if (appear && i != linha) ans = false;
                    appear = true, linha = i;
                }
                aux = j;
            }
        }
        //printf ("i %d q %d\n", i, q);
        if (q == 1) {
            cont++;
            for (int j = 0; ans && j < m; j++) 
                if ((cont > 2 || appear) && (grid[i][j] == '*' && coluna != -1 && j != coluna)) {
         //           printf ("i %d j %d\n", i, j);
                    ans = false; 
                }
        }
        qRow[i] = q;
        if (coluna == -1 && q == 1) coluna = aux;
        //printf ("linha %d coluna %d\n", linha, coluna);
    }
    if (!ans) printf ("NO\n");
    else {
        linha = -1;
        for (int i = 0; i < n; i++) {
            if (qRow[i] > 1) linha = i;
            else if (qRow[i] == 1) aux = i;
        }
        if (linha == -1) linha = aux;
        appear = false;
        for (int i = 0; !appear && i < n; i++) {
            for (int j = 0; !appear && j < m; j++) {
                if (grid[i][j] == '*' && i != linha) 
                    appear = true, coluna = j;
            }
        }
        printf ("YES\n");
        linha++, coluna++;
        if (appear) printf ("%d %d\n", linha, coluna);
        else printf ("%d 1\n", linha);
   }
}

