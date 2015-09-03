#include <cstdio>
//faço o quanto ficou ligado menos o quanto ficou parado
using namespace std;

int main () {
	int n, ant, atual, parado = 0, ligado;
	scanf ("%d", &n);
	scanf ("%d", &ant);
	atual = ant;
	n -= 1;
	parado += ant - 0;
	while (n--) {
		scanf ("%d", &atual);
		if (atual - ant > 10) parado += atual - ant - 10;
		ant = atual;
	}
	ligado = atual + 10 - parado;
	printf ("%d\n", ligado);
}