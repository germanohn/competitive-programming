#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 2020

using namespace std;

int p, n, memo[MAX][MAX], peso[MAX], valor[MAX];

int mochila (int obj, int aguenta) {
	if (memo[obj][aguenta] != -1) return memo[obj][aguenta];
	if (obj > n || aguenta == 0) return memo[obj][aguenta] = 0;
	int naocoloca = mochila (obj + 1, aguenta);
	int coloca;
	if (peso[obj] <= aguenta) {
		coloca = valor[obj] + mochila (obj + 1, aguenta - peso[obj]);
		return memo[obj][aguenta] = max (naocoloca, coloca);
	}
	return memo[obj][aguenta] = naocoloca;
}

int main () {
	memset (memo, -1, sizeof (memo));
	scanf ("%d %d", &p, &n);
	for (int i = 1; i <= n; i++) 
		scanf ("%d %d", &peso[i], &valor[i]);
	printf ("%d\n", mochila (1, p));
}
