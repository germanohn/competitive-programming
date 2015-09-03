/*escolhe sempre a que termina primeiro, entao ordena pela fim da
consulta*/
#include <cstdio>
#include <algorithm>
#define MAX 10005

using namespace std;

struct tabela {
	int ini, fim;
};

tabela cons[MAX];
int n, x, y;

bool compara (tabela x, tabela y) {
	return x.fim < y.fim;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d%d", &cons[i].ini, &cons[i].fim);
	sort (cons, cons + n, compara);
	int cont = 1;
	int livre = cons[0].fim;
	for (int i = 1; i < n; i++) {
		if (cons[i].ini >= livre) {
			cont++;
			livre = cons[i].fim;
		}
	} 
	printf ("%d\n", cont);
}