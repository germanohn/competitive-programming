#include <bits/stdc++.h>
#define MAX 100
using namespace std;
/*tem n numeros pra distribuir, pra cada um ver qual linha tem mais
  desse numero*/
bool used[MAX]; 
int ans[MAX];
int A[MAX][MAX];

int main () {
    int n, cont;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            scanf ("%d", &A[i][j]);
    for (int i = 1; i <= n; i++) {
        cont = n-i;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                int num = 0;
                for (int k = 1; k <= n; k++) 
                    num += (A[j][k] == i);
                if (num == cont) {
                    used[j] = true;
                    ans[j] = i;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) 
        printf ("%d ", ans[i]);
    printf ("\n");
}
