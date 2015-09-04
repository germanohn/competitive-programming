#include <stdio.h>

char[6] palavraEsquerda;
char[6] palavraDireita;
int tamanhoEsquerda;
int tamanhoDireita;

int main() {
        char c;
        for (int i = 0; i < 7; i++) {

                
        return 0;
}


int pesaPalavra(char[] palavra, tamanho) {
        int peso = 0;
        for (int i = 0; i < tamanho; i++) peso += pesaLetra(palavra[i]); 
        return peso;
}

int pesaLetra(int letra) {
        int peso = 0;
        while (letra != 0) {
                if (letra%2 == 0) peso += 250;
                else peso += 500;
                letra = letra/10;
        }
}

void imprimeEquilibrada() {
        printf("........||........\n");
        printf(".../\...||.../\...\n");
        printf("../..\..||../..\..\n");
        printf("./....\.||./....\.\n");
        printf("/%s\||/%s%c\n", palavraEsquerda, palavraDireita, 92);
        printf("\______/||\______/\n");
        printf("........||........\n");

}

void imprimeDesequilibradaEsquerda(char[] palavraEsquerda, char[] palavraDireita) {
        printf("........||.../\...\n");
        printf("........||../..\..\n");
        printf(".../\...||./....\.\n");
        printf("../..\..||/%s%c\n", palavraDireita, 92);
        printf("./....\.||\______/\n");
        printf("/%s\||........\n", palavraEsquerda);
        printf("\______/||........\n");
}

void imprimeDesequilibradaDireita(char[] palavraEsquerda, char[] palavraDireita) {
        printf(".../\...||........\n");
        printf("../..\..||........\n");
        printf("./....\.||.../\...\n");
        printf("/%s\||../..\..\n", palavraEsquerda);
        printf("\______/||./....\.\n");
        printf("........||/%s%c\n", palavraDireita, 92);
        printf("........||\______/\n")
}
