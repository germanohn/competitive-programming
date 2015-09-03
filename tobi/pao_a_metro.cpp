#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

int n, k, pao[MAX];

int main () {
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf ("%d", &pao[i]);
	sort (pao, pao + k);
	int lo = 1, hi = pao[k-1], mid;
	while (lo != hi) {
		int total = 0;
		mid = (lo + hi + 1)/2;
		for (int i = 0; i < k; i++)
			total += pao[i]/mid;

		if (total >= n) lo = mid;
		
		if (total < n) hi = mid-1;
	}
	printf ("%d\n", hi);
}