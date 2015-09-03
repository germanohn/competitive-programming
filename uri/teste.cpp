#include <cstdio>
#include <set>
#define MAX 100010

using namespace std;

int n, aux, pto[MAX];
set<int> sum;

int main () {
	while (scanf ("%d", &n) && n != 0) {
		int soma = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &pto[i]);
			soma += pto[i];
			sum.insert (soma);
		}
		set<int> ::iterator it;
	
		int arco = soma/3;
	
		for (it = sum.begin (); it != sum.end (); it++) {
			int cont = 0;
			for (int j = 1; j <= 2; j++) {
				int quero = *it + arco*j;
				
				if (sum.find (quero) != sum.end ())
					cont++;
			}
			if (cont == 2) ans++;
		}
		printf ("%d\n", ans);
		sum.clear ();
	}
}