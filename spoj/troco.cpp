#include <cstdio>
#include <cstring>
#define MAX 1010
#define MAXN 100010

using namespace std;

int v, m, moeda[MAX], memo[MAX][MAXN];

bool dp (int i, int custo) {
	if (memo[i][custo] != -1) return memo[i][custo];
	if (i > m) return memo[i][custo] = 0;
	if (custo == moeda[i]) return memo[i][custo] = 1;
	int usa, nao_usa;
	nao_usa = dp (i + 1, custo);
	if (moeda[i] < custo) {
		usa = dp (i + 1, custo - moeda[i]);
		if (nao_usa)
			return memo[i][custo] = nao_usa;
		if (usa)
			return memo[i][custo] = usa;
	}
	return memo[i][custo] = nao_usa;
}

int main () {
	memset (memo, -1, sizeof memo);
	scanf ("%d %d", &v, &m);
	for (int i = 1; i <= m; i++) 
		scanf ("%d", &moeda[i]);
	if (dp (1, v)) printf ("S\n");
	else printf ("N\n");
}