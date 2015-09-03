#include <cstdio>
#include <algorithm>

using namespace std;

int menor, mid, maior, l;
int v[3];

int main () {
	scanf ("%d%d%d%d", &v[0], &v[1], &v[2], &l);
	sort (v, v + 3);
	menor = v[0], mid = v[1], maior = v[2];
	int cont = 0;
	if (mid > (maior-menor) && mid < maior+menor) cont++;
	for (int i = 1; i <= l; i++) {
		int aux = 3;
		while (aux--) {
			if (aux == 2) menor++;
			else if (aux == 1) {
				menor--;
				mid++;	
			} 
			else if (aux == 0) {
				maior++;
				mid--;
			}
			if (mid > (maior-menor) && mid < maior+menor) cont++; 
		}
	}
	printf ("%d\n", cont);
}