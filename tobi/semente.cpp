#include <cstdio>
#define MAX	1010

using namespace std;

int f, r, v[MAX];

int main () {
	scanf ("%d%d", &f, &r);
	for (int i = 0; i < r; i++) 
		scanf ("%d", &v[i]);
	int maior = 0;
	if (v[0]-1 > maior) maior = v[0]-1;
	if (f - v[r-1] > maior) maior = f - v[r-1];
	for (int i = 1; i < r; i++) {
		int a = (v[i] - v[i-1])/2;
		if (a > maior) maior = a; 
	}
	printf ("%d\n", maior);
}