#include <cstdio>
#include <cstring>
#define MAX 100010

using namespace std;

int n, aux, pto[MAX];
bool sum[MAX];

int main () {
	while (scanf ("%d", &n) && n != 0) {
		memset (sum, false, sizeof sum);
		int soma = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &pto[i]);
			soma += pto[i];
			sum[i] = ;
		}
		int arco = soma/3;
		for (int i = 1; i <= n; i++) {
			int cont = 0;
			for (int j = 1; j <= 2; j++) {
				int lo = 1, hi = n, mid, quero = sum[i] + arco*j;
				//printf ("quero %d\n", quero);
				while (lo != hi) {
					mid = (lo + hi)/2;
					if (sum[mid] == quero) {
						cont++;
						//printf ("cont %d\n", cont);
						break;
					}
					else if (sum[mid] > quero) hi = mid;
					else if (sum[mid] < quero) lo = mid+1;
					//printf ("lo %d hi %d\n", lo, hi);
				}
			}
			if (cont == 2) ans++;
		}
		printf ("%d\n", ans);
	}
}