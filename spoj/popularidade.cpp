#include <cstdio>
#include <cstring>
#define MAX 105

using namespace std;

int n, freq[MAX], voto;

int main () {
	while (scanf ("%d", &n) && n != 0) {
		memset (freq, 0, sizeof (freq));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf ("%d", &voto);
				if (voto == 1) freq[j]++;
			}
		int maior = 0;
		for (int j = 1; j <= n; j++) 
			if (freq[j] > maior) maior = freq[j];
		printf ("%d\n", maior);
	}
}