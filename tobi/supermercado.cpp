#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int> > ponto;
int s, x, y;

int main () {
	int cont = 1;
	while (scanf ("%d", &s) && s != 0) {
		int min_x = INT_MAX, max_x = INT_MIN;
		int min_y = INT_MAX, max_y = INT_MIN;
		int menor = INT_MAX;
		while (s--) {
			scanf ("%d%d", &x, &y);
			ponto.push_back (make_pair (x, y));
			if (x < min_x) min_x = x;
			if (x > max_x) max_x = x;
			if (y < min_y) min_y = y;
			if (y > max_y) max_y = y;
		}
		for (int i = min_x; i <= max_x; i++) {
			for (int j = min_y; j <= max_y; j++) {
				int d = 0;
				for (int l = 0; l < ponto.size (); l++) {
					d += abs (i - ponto[l].first) + abs(j - ponto[l].second);
				}
				if (d < menor) {
					x = i;
					y = j;
					menor = d;
				}
			}
		}
		printf ("Teste %d\n%d %d\n\n", cont, x, y);
		cont++;
		ponto.clear ();
 	}
}