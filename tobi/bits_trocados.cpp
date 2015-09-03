/*enquanto o valor que preciso retirar for maior que a nota em
questao entao quant++*/
#include <cstdio>

using namespace std;

int n, cont = 1, v;
int din[4] = {50, 10, 5, 1};
int rta[4];

int main () {
	while (scanf ("%d", &v) && v != 0) {
		for (int i = 0; i < 4; i++) {
			int quant = 0;
			while (din[i] <= v) { 
				quant++;
				v -= din[i];
			}
			rta[i] = quant; 
		}
		printf ("Teste %d\n%d %d %d %d\n\n", cont, rta[0], rta[1], rta[2], rta[3]);
		cont++;
	}
}