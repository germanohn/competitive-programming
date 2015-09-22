#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n, v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    int maior = 1, ant = v[0], atual, tmp = 1;
    for (int i = 1; i < n; i++) {
        atual = v[i];
        if (atual >= ant) {
            tmp++;
            if (tmp > maior)
                maior = tmp;
        }
        else 
            tmp = 1;
        ant = v[i];
    }
    printf ("%d\n", maior);
} 
