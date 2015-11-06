#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int t;
char A[10][10], B[10][20];
vector<char> e, d;

int main () {
	scanf ("%d", &t);
	int esq = 3, dir = 4;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			if (j != esq && j != dir) 
				A[i][j] = 46;
			else if (j == esq)
				A[i][j] = 47;
			else 
				A[i][j] = 92;
		}
		esq--, dir++;
	}
	A[4][0] = 92;
	A[4][7] = 47;
	for (int i = 1; i < 7; i++) {
		A[4][i] = '_';
	}
	int cont = 1;
	for (int l = 0; l < t; l++) {
		for (int j = 0; j < 8; j++)
			scanf ("%s", B[j]);
		esq = 0, dir = 0;
		int hEsq, hDir;
		for (int i = 3; i < 6; i++) {
			for (int j = 1; j < 17; j++) {
				if (B[i][j] >= 'A' && B[i][j] <= 'Z') {
					if (j < 8) { 
						esq += B[i][j];
						e.pb (B[i][j]);
						hEsq = i;
					}
					else {
						dir += B[i][j];
						d.pb (B[i][j]);
						hDir = i;
					}
				}
			}
		}
		if ((esq > dir && hEsq > hDir) || (esq < dir && hEsq < hDir) || (esq == dir && hEsq == hDir))
			printf ("Case %d:\nThe figure is correct.\n", cont);
		int contDir = 0, contEsq = 0;
		else if (esq > dir){//balanca esq em cima
			for (int i = 0; i < 8; i++) {//sao oito linhas
				for (int j = 0; j < 18; j++) {//sao 18 colunas
					if (j < 8) {//antes dos | |
						if (i < 5) {//sera o formato da balanca
							if (i == 3 && j > 0 && j < 7) {
								if (contEsq < e.size ()) 
									printf ("%c", e[contEsq++]);
								printf (".");
							}
							else printf ("%c", A[i][j]);
						}
						else
							printf (".");
					}
					else if (j == 8 || j == 9)//| |
						printf ("|");
					else if (j > 9) {//balanca dir em baixo
						if (j < 17) {
							if (i < 2)
								printf (".");
							else {//sera o formato da balanca
								if ()
							}
						}
					}
				}
			}
		}
		else if (esq < dir) {

		}
		else {

		}
	}
}
