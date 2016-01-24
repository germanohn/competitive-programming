#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n, primo[MAX];

void crivo () {
    for (int i = 2; i <= MAX/2; i++) {
        if (primo[i] != 0)
            for (int j = 2; j * i <= MAX; j++) 
                primo[i*j] = 0;
    }
}

int main () {
    for (int i = 2; i <= MAX; i++) 
        primo[i] = i;
    crivo ();
    int k = 0; 
    for (int i = 2; i < MAX; i++)
        if (primo[i] != 0)
            primo[k++] = primo[i];

    while (scanf ("%d", &n) && n != 0) {
        int soma, cont = 0;
        for (int i = 0; primo[i] <= n; i++) {
            soma = 0;
            for (int j = i; soma < n; j++) {
                soma += primo[j];   
            }
            if (soma == n) cont++;
        }
        printf ("%d\n", cont);     
    }
}
