#include <bits/stdc++.h>
//tamanho de string é a ultima posiçao no vetor
//para montar o numero se começa pelo final do numero
//cuidado com o em tirar o '0' na hora de passar para numero porque o caractere 0 tem valor 48 entao todo caractere se subtrai '0'
//ja para formar o numero em forma de caractere a partir do numero tem que colocar o + '0'
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
            //constroi como numero para poder aumentar
            for (int i = tam; i >= 0; i--) {
                num += (c[i] - '0') * pot;
                pot *= 10;
            }
            num++;
            //devolve para a forma de string para poder comparar tendo os 0 na frente
            for (int i = tam; i >= 0; i--) {
                char aux;
                if (num != 0) {
                    aux = (num % 10) + '0';
                    num /= 10;
                    c[i] = aux;
                }
                else 
                    c[i] = '0'; 
            }
            c[tam + 1] = '\0';
            cont++;
        }
        printf ("%d\n", cont);
    }
}
