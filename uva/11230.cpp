#include <cstdio>
using namespace std;

int tra[105][105], des[105][105];
int n, m, r, c, cont;
char cc;

int main () {
    while (scanf ("%d %d %d %d", &n, &m, &r, &c) && n != 0) {
        cont = 0;
        bool f = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf (" %c", &cc);
                des[i][j] = cc - '0';
                tra[i][j] = 0;
            }
        }

        for (int i = 0; i < n && f; i++) {
            for (int j = 0; j < m && f; j++) {
                if (des[i][j] != tra[i][j]) {
                    if (r > n-i || c > m-j) {
                        printf ("-1\n");
                        f = false;
                    }
                    for (int k = i; k < i+r && f; k++) {
                        for (int l = j; l < j+c; l++) {
                            if (tra[k][l] == 1) tra[k][l] = 0;
                            else tra[k][l] = 1;
                        }
                    }
                    cont++;
                }
            }
        }

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf ("%d ", tra[i][j]);
            }
            printf ("\n");
        }*/

        for (int i = 0; i < n && f; i++) {
            for (int j = 0; j < m && f; j++) {
                if (tra[i][j] != des[i][j]) {
                    printf ("-1\n");
                    f = false;
                }
            }
        }
        if (f) printf ("%d\n", cont);
    }
}
