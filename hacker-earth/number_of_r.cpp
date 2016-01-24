#include <iostream>
#include <cstdio>
#include <climits>
#define MAX 1000005
using namespace std;

int main() {
	char c[MAX];
	int t, ind, cont, cont_r, cont_k, ini, melhor tmp;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s", c);
		melhor = INT_MIN;
		string s = c;
		cont = 0;
		ini = 0;
		int aux = ini;
		i = 0;
		while (i <= s.size ()) {
			if (s[i] == 'R') 
				cont ++;
			i++;
		} 
		melhor = cont;
		while (ini <= s.size ()) {
			cont_k = 0;
			cont_r = 0;
			i = ini;
			while (i <= s.size ()) {
				tmp = cont;
				if (s[i] == 'K') 
					cont_k++;
				else 
					cont_r++;
				tmp = tmp - cont_r + cont_k;
				if (tmp > melhor) 
					melhor = tmp;
				i++;
			}
			ini++;
		}
		printf ("%d\n", melhor);
	}
}