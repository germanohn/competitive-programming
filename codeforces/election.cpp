#include <cstdio>
#define MAX 105

using namespace std;

int main () {
	int n, m, cidade[MAX], estado[MAX], maior, ind;
	int freq[MAX];
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		maior = -1;
		for (int j = 1; j <= n; j++) {
			scanf ("%d", &cidade[j]);
			if (cidade[j] > maior) {
				maior = cidade[j];
				estado[i] = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) 
		freq[i] = 0;
	for (int i = 1; i <= m; i++) 
		freq[estado[i]]++;
	maior = -1;
	ind = 1;
	for (int i = 1; i <= n; i++){
		if (freq[i] > maior) {
			maior = freq[i];
			ind = i;
		}
	}	
	printf ("%d\n", ind);
}