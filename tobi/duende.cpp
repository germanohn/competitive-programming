#include <cstdio>
#include <queue>

using namespace std;

int n, m, a, b, cx, cy;
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};
int A[15][15];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf ("%d", &A[i][j]);
			if (A[i][j] == 3) {
				cx = i;
				cy = j;
				A[i][j] = 0;
			}
			else if (A[i][j] == 0) 
				A[i][j] = -1;
			else if (A[i][j] == 1) 
				A[i][j] = 0;
		}
	}
	queue<pair<int, int> > q;
	q.push (make_pair (cx, cy));
	while (!q.empty ()) {
		pair<int, int> c = q.front ();
		int a = c.first, b = c.second;
		q.pop ();
		for (int k = 0; k < 4; k++) {
			if (a + x[k] >= 0 && a + x[k] < n && b + y[k] >= 0 
				&& b + y[k] < m) {
				if (A[a + x[k]][b + y[k]] == 0 && ((a + x[k] != cx) || (b + y[k] != cy))) {
					A[a + x[k]][b + y[k]] = A[a][b] + 1;
					q.push (make_pair (a + x[k], b + y[k]));
				}
				if (A[a + x[k]][b + y[k]] == -1 && ((a + x[k] != cx) || (b + y[k] != cy))) {
					printf ("%d\n", A[a][b] + 1);
					return 0;	
				}
			}	
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				printf ("%d ", A[i][j]);
			printf ("\n");
		}
		printf ("\n\n");
	}
}