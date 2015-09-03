#include <cstdio>
#include <algorithm>
#define MAX 10010
using namespace std;

int x, y, a, b;

int main () {
	int cont = 0;
	pair<int, int> heads[MAX];
	scanf ("%d %d %d %d", &x, &y, &a, &b);
	int k = 0;
	for (int i = a; i <= x; i++) 
		for (int j = b; j <= y; j++) 
			if (i > j) {
				heads[k].first = i;
				heads[k].second = j;
				cont++;
				k++;
			}
	if (cont == 0) printf ("0\n");
	else {
		printf ("%d\n", cont);
		for (int i = 0; i < cont; i++)
			printf ("%d %d\n", heads[i].first, heads[i].second);
	}
}