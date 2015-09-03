/*quer o minimo de pa's que consigo formar. entao faço guloso.
a melhor opçao. 
so preciso analisar pa quando for pelo menos 3 caras*/
#include <cstdio>
#define MAX 100005

using namespace std;

int n, seq[MAX], cont = 1, razao, tam = 1;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &seq[i]);
		if (tam == 2) razao = seq[i] - seq[i-1];
		if (tam >= 3) {
			if (seq[i] - seq[i-1] != razao) {
				tam = 1;
				cont++;
			}
		}
		tam++;
	}
	printf ("%d\n", cont);
}
