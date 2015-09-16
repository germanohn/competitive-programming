#include <bits/stdc++.h>

using namespace std;

int n, me[2005][2005], memo[2005][2005];
char c[2005];


int pd2 (int i, int j) {
	if (i > j) {
		return 1;
	}
	int &m = me[i][j];
	if (m != -1) return m;
	if (c[i] == c[j]) {
		return pd2 (i + 1, j - 1);
	}
	return -1;
}

int pd (int i, int j) {  
	if (i == n) return 0;
	if (j == n && i == n - 1) return 0;
	if (j == n) return 123456;
	int &m = memo[i][j];
	if (m != -1) return m;
	//printf ("pd2  %d\n", pd2 (i , j));
	if (pd2 (i , j) == 1) {
		return m = min (1 + pd (i + 1, j + 1), pd (i, j + 1));
	}
	printf ("t\n");
	return m = 1 + pd (i + 1, j);
}

int main () {
	int cont = 1;
	while (scanf ("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) { 
				me[i][j] = -1;
				memo[i][j] = -1;
			}

		scanf ("%s", c);
		printf ("%s\n", c);
		printf ("Teste %d\n%d\n\n", cont++, pd (0, 0));
	}
}
