#include <cstdio>
#define MAX 10005

using namespace std;

int main () {
	int t, n, m;
	int boy[MAX], girl[MAX];
	scanf ("%d%d%d", &t, &m, &n);
	for (int i = 0; i < m; i++) 
		scanf ("%d", &boy[i]);
	for (int i = 0; i < n; i++) 
		scanf ("%d", &girl[i]);
	qsort (boy, m, size (int));
	qsort (girl , girl + n);
	for (int i = m-1; i >= 0; i++) {
		while (j > 0) {
			if (boy[i] > )
		}
	}
}