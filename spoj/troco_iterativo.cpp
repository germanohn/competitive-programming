#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1010
#define MAXN 100010

using namespace std;

int v, m, moeda[MAX], memo[MAXN];

bool dp (int i, int custo) {
	for (int k = m; k >= 1; k--) {
		for (int valor = v; valor >= moeda[k]; valor--) {
			if (memo[valor-moeda[k]] == 1)
				memo[valor] = 1;
		}
	}
	if (memo[v] == 1) return true;
	return false;
}

int main () {
	memset (memo, 0, sizeof memo);
	memo[0] = 1;
	scanf ("%d %d", &v, &m);
	for (int i = 1; i <= m; i++) 
		scanf ("%d", &moeda[i]);
	sort (moeda + 1, moeda + m + 1);
	if (dp (1, v)) printf ("S\n");
	else printf ("N\n");
}