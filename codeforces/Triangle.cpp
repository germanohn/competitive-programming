#include <cstdio>
#include <cmath>

using namespace std;

int v[3], a, b;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

bool pitago (int x, int y, int z) {
	return pow (x, 2) == pow (y, 2) + pow (z, 2);
}
	
int main () {
	for (int i = 0; i < 3; i++) {
		scanf ("%d %d", &a, &b);
		v[i] = abs(a-b);	
	}
	sort(v, v + 3);
	if (pitago (v[2], v[1], v[0])) printf ("RIGHT\n");
	else {
		bool f = false;
		for(int j = 0; j < 3; j++) {
			for (int i = 0; i < 4; i++) {
				v
			}
		}
	}



}