#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 105

using namespace std;

vector<pair<int, int> > pista;
int A[MAX][MAX];
int k, n, x, y, d;

int main () {
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			A[i][j] = 0;
	for (int i = 0; i < k; i++) {
		scanf ("%d%d%d", &x, &y, &d);
		A[x][y] = d;
		pista.push_back (make_pair (x, y));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == 0) {
				for (int l = 0; l < k; l++) {
					d = abs (i - pista[l].first) + abs (j - pista[l].second);
					if (d == A[pista[l].first][pista[l].second])
						A[i][j]++;
				}
				A[i][j] /= k;
			}
		}
	}
	for (int i = 0; i < k; i++)
		A[pista[i].first][pista[i].second] = 0;
	int cont = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == 1) {
				cont++;
				x = i;
				y = j;
			}
			if (cont >= 2)
				break;
		}
	}
	if (cont == 1)
		printf ("%d %d\n", x, y);
	else 
		printf ("-1 -1\n");
}