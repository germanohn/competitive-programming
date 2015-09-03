#include <cstdio>
#include <algorithm>
#define MAX 110

using namespace std;

int n, cand[MAX];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &cand[i]);
	}
	sort (cand + 1, cand + n);
	int cont = 0;
	while (cand[0] <= cand[n-1]) {
		cand[n-1] -= 1;
		cand[0] += 1;
		sort (cand + 1, cand + n);
		cont++;
	}
	printf ("%d\n", cont);
}