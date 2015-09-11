#include <cstdio>
#define MAX 100010

using namespace std;

int div[MAX], cont, n, x;

void divisores (int num) {
	int j = 0;
	for (int i = 1; i <= num/2 && i <= n; i++) { 
		if (num % i == 0 && num/i <= n) { 
			div[j++] = i;
			cont++;
		}
	}
	if (num <= n) {
		div[j] = num;
		cont++;
	}
}

int main () {
	scanf ("%d %d", &n, &x);
	divisores (x);
	printf ("%d\n", cont);
}
