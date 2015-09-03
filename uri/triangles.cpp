#include <cstdio>
#define MAX 100010

using namespace std;

int n, aux, sum[MAX], pto[MAX];

int main () {
	while (scanf ("%d", &n) != EOF) {
		int soma = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &pto[i]);
			soma += pto[i];
			sum[i] = soma;
		}
		if (soma % 3 != 0) printf ("0\n");
		else {
			int arco = soma/3;
			for (int i = 1; i <= n/3; i++) {
				int cont = 0;
				for (int j = 1; j <= 2; j++) {
					int lo = 1, hi = n, mid, quero = (sum[i] + arco*j)%soma;
					while (lo != hi) {
						mid = (lo + hi)/2;
						if (sum[mid] == quero) {
							cont++;
							break;
						}
						else if (sum[mid] > quero) hi = mid;
						else if (sum[mid] < quero) lo = mid+1;
					}
				}
				if (cont == 2) ans++;
			}

		printf ("%d\n", ans);
		}
	}
}