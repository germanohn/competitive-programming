#include <cstdio>

using namespace std;

int main () {
	int t, s, q, down, listen = 0, ans = 1;
	scanf ("%d%d%d", &t, &s, &q);
	down = s;
	while (down < t) {
		down += q - 1;
		listen += q;
		if (down >= t) break;
		if (down == listen) {
			listen = 0;
			ans++;
		}
	}
	printf ("%d\n", ans);
}