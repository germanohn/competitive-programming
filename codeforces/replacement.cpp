#include <cstdio>
#include <iostream>
#define MAX 300005

using namespace std;

int main () {
	int n, m, ant, cont = 0;
	scanf ("%d%d", &n, &m);
	char c[MAX], a;
	while (i < n) {
		cin >> c[i];
		if (c[i] == '.') {
			i++
			while (c[i] == '.') {
				cont++;
				i++;
			}
		}
		i++;
	}

	scanf ("%c%s", &a, c);
	int aux = m;
	while (m--) {
		int num;
		scanf ("%d %c", &num, &a);
		c[num-1] = a;
		int i = 0;
		if (aux < m-1) {
			if (num == 1) 
				if (c[num] == '.') cont++;
			else {
				if (c[num] == '.' && c[num-2] != '.') cont++;
				else if (c[num] == '.' && c[num-2] == '.') cont = cont + 2;
			}

		}
		else {
			while (i < n) {
				if (c[i] == '.') {
					i++;
					while (c[i] == '.') {
						cont++;
						i++;
					}
				}
				i++;
			}
		}
		ant = cont;
		printf ("%d\n", cont);
	}
}