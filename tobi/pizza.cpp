#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100010

using namespace std;

int n, fatia[MAX], max_total, x, y;

void kadane () {
    int x_temp = 0;
    max_total = -1;
    int max_atual = 0;
    for (int i = 0; i < n; i++) {
        max_atual = max_atual + fatia[i];
        if (max_atual < 0) {
            max_atual = 0;
            x_temp = i + 1;
        }
        if (max_atual > max_total) {
            max_total = max_atual;
            x = x_temp;
            y = i;
        }
    }
}

int main () {
    scanf ("%d", &n);
    int total = 0, maxi = 0, mini = 0, soma;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &fatia[i]);
        total += fatia[i];
    }    
    kadane ();
    maxi = max_total;
    for (int i = 0; i < n; i++) 
        fatia[i] = -fatia[i];
    kadane ();
    mini = -max_total;

    soma = max (total - mini, maxi);
    printf ("%d\n", soma);
}
