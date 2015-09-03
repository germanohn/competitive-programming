#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#define MAX 100005

using namespace std;

int main () {
	int n, l, trocados, menor = INT_MAX;
	vector<int> arm;
	while (scanf ("%d%d", &n, &l) && n != 0) {
		printf ("oi\n");
		int aux;
		for (int i = 1; i <= l; i++) {
			scanf ("%d", &aux);
			arm.push_back (aux);
		} 
		printf ("oi1\n");
		for (int i = 1; i <= l-n+1; i++) {
			int livre;
			bool f = true; 
			int var = arm[i-1] + n - 1;
			vector<int> ::iterator it;
			it = upper_bound (arm.begin (), arm.end (), var);
			livre = it - i;
			trocados = n - livre;
			printf ("trocados %d\n", trocados);
			if (trocados < menor) menor = trocados;
		}
		printf ("%d\n", menor); 
	}
}