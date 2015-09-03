#include <cstdio>
#define MAX 100

using namespace std;

int pilha (int n){}

int main () {
	char v[MAX];
	int a, b, ini = 0, fim = 15;
	for (int i = 0; i <= 15; i++) 
		v[i] = 'A' + i;
	for (int i = 0; i < 15; i++) {
		scanf ("%d%d", &a, &b);
		if (a > b) v[fim + 1] = v[ini];
		else v[fim + 1] = v[ini + 1];
		ini += 2;
		fim += 1;
	} 
	printf ("%c\n", v[fim]);
}