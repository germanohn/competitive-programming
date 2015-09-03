#include <cstdio>
#define MAX 10010

using namespace std;

int n, x, y, v[MAX], ini, fim, max_total, a, b;

void kadane () {
    int x_temp = 1;
    int max_atual = 0; 
    max_total = -1;
    for (int i = 1; i <= n; i++) {
        max_atual = max_atual + v[i];
        if (max_atual < 0) {
            max_atual = 0;
            x_temp = i + 1;
        }
        if (max_atual >= max_total) {
            max_total = max_atual;
            ini = x_temp;
            fim = i;
        }
    }
}

int main () {
    int cont = 1;
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 1; i <= n; i++) {
            scanf ("%d %d", &a, &b);
            v[i] = a - b;
        }
        kadane ();
        printf ("Teste %d\n", cont++);
        if (max_total > 0) 
            printf ("%d %d\n\n", ini, fim);
        else
            printf ("nenhum\n\n");
    }
}
