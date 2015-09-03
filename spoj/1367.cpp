#include <cstdio>

using namespace std;

int troca (char letra) {
	if (letra == 'A') return 0;
	else if (letra == 'B') return 1;
	else if (letra == 'C') return 2;
	else if (letra == 'D') return 3;
	return 4;
}

int main () {
	int n, senha[3][10], atual[3][10];
	int num;
	char letra;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			senha[i][j] = -1;
	int cont = 1;
	while (scanf ("%d", &n) && n != 0) {
		int aux = n;
		while (aux--) {
			for (int i = 0; i < 5; i++)
				scanf ("%d%d", &atual[1][i], &atual[2][i]);
			for (int i = 0; i < 6; i++){
				scanf ("%c%c", &letra, &letra);
				num = troca (letra);
				if (aux == n - 1) {
					senha [1][i] = atual[1][num];
					senha [2][i] = atual[2][num];
				}
				else {
					if (senha[1][i] != atual[1][num] && senha[1][i] != atual[2][num])
						senha[1][i] = -1;
					else if (senha[2][i] != atual[1][num] && senha[2][i] != atual[2][num])
						senha[2][i] = -1;
				}
			}
		}
		bool f = false;
		printf ("Teste %d\n", cont);
		for (int i = 0; i < 6; i++) {
			if (f) printf (" ");
			if (senha[1][i] != -1) printf ("%d", senha[1][i]);
			else printf ("%d", senha[2][i]);
			f = true;
		}
		printf ("\n\n");
		cont++;
	}
	return 0;
}