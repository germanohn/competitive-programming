#include <bits/stdc++.h>

using namespace std;

char c[10], a[2];

bool palin (char pa[], int tam) {
    for (int i = 0; i <= tam / 2; i++) {
        if (pa[i] != pa[tam - i]) 
            return false;
    } 
    return true;
}

int main () {
    int tam, cont;
    a[0] = '0', a[1] = '\0';
    while (scanf ("%s", c) && strcmp (c, a) != 0) {
        cont = 0;
        tam = strlen (c) - 1;
        while (!palin (c, tam)) {
            int num = 0, pot = 1;
            for (int i = tam; i >= 0; i--) {
                num += (c[i] - 48) * pot;
                pot *= 10;
            }
            num++;
            for (int i = tam; i >= 0; i--) {
                char aux;
                if (num != 0) {
                    aux = (num % 10) + 48;
                    num /= 10;
                    c[i] = aux;
                }
                else 
                    c[i] = 48; 
            }
            c[tam + 1] = '\0';
            cont++;
        }
        printf ("%d\n", cont);
    }
}
