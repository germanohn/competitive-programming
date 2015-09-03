//knight moves
/*nao precisa limpar a fila pois toda vez que começa outro scanf declaro ela de novo*/
#include <cstdio>
#include <queue>

using namespace std;

char a, b;
int sx, sy, ex, ey;
int kx[] = {-1, -1, -2, -2, +1, +1, +2, +2};
int ky[] = {-2, +2, -1, +1, -2, +2, -1, +1};
int A[8][8];

int main () {
	while (scanf ("%c%d %c%d", &a, &sy, &b, &ey) != EOF) {
		sx = a - 'a';
		sy--;
		ex = b - 'a';
		ey--;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				A[i][j] = -1;
		A[sx][sy] = 0;
		queue<pair<int, int> > q;
		q.push (make_pair (sx, sy));
		while (!q.empty ()) {
			pair <int, int> c = q.front ();
			int x = c.first, y = c.second;
			if (x == ex && y == ey) break;
			q.pop ();
			for (int i = 0; i < 8; i++) {
				if (x + kx[i] >= 0 && x + kx[i] < 8 && 
					y + ky[i] >= 0 && y + ky[i] < 8) {
					if (A[x + kx[i]][y + ky[i]] == -1) {
						q.push (make_pair (x + kx[i], y + ky[i]));
						A[x + kx[i]][y + ky[i]] = A[x][y] + 1;
					}
				}
			}
		}
		printf ("To get from %c%d to %c%d takes %d knight moves.\n", a, sy + 1, b, ey + 1, A[ex][ey]);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				printf ("%d ", A[i][j]);
			}
			printf ("\n");
		}
		scanf ("%c", &a);
	}
}

/*para nao esquecer:
			TUDO ISSO:
			if (x-2 >= 0 && y+1 < 8){
				if (A[x-2][y+1] == -1) {
					A[x-2][y+1] = A[x][y] + 1;
					q.push (make_pair (x-2, y+1));
				}
			}
			if (x-2 > 0 &&  y-1 > 0){
				if (A[x-2][y-1] == -1) {
					A[x-2][y-1] = A[x][y] + 1;
					q.push (make_pair (x-2, y-1));
				}
			}
			if (x-1 >= 0 && y+2 < 8){
				if (A[x-1][y+2] == -1) {
					A[x-1][y+2] = A[x][y] + 1;
					q.push (make_pair (x-1, y+2));
				}
			}
			if (x-1 > 0 && y-2 > 0){
				if (A[x-1][y-2] == -1) {
					A[x-1][y-2] = A[x][y] + 1;
					q.push (make_pair (x-1, y-2));
				}
			}
			if (x+1 < 8 && y+2 < 8){
				if (A[x+1][y+2] == -1) {
					A[x+1][y+2] = A[x][y] + 1;
					q.push (make_pair (x+1, y+2));
				}
			}
			if (x+1 < 9 && y-2 > 0){
				if (A[x+1][y-2] == -1) {
					A[x+1][y-2] = A[x][y] + 1;
					q.push (make_pair (x+1, y-2));
				}
			}
			if (x+2 < 9 && y-1 > 0){
				if (A[x+2][y-1] == -1) {
					A[x+2][y-1] = A[x][y] + 1;
					q.push (make_pair (x+2, y-1));
				}
			}
			if (x+2 < 9 && y+1 < 9){
				if (A[x+2][y+1] == -1) {
					A[x+2][y+1] = A[x][y] + 1;
					q.push (make_pair (x+2, y+1));
				}
			}
			VIROU:
			for (int i = 0; i < 8; i++) {
				if (x + kx[i] >= 0 && x + kx[i] < 8 && 
					y + ky[i] >= 0 && y + ky[i] < 8) {
					q.push (make_pair (x + kx[i], y + ky[i]))
					A[x + kx[i]][y + ky[i]] = A[x][y] + 1;
				}
			}
		*/