#include <cstdio>
#include <algorithm>
#define MAX 100010

using namespace std;

int a, b, k, m, va[MAX], vb[MAX], x, y;
int ka[MAX], mb[MAX];

int main () {
	scanf ("%d%d %d%d", &a, &b, &k, &m);
	for (int i = 0; i < a; i++)
		scanf ("%d", &va[i]);
	for (int i = 0; i < b; i++)
		scanf ("%d", &vb[i]);
	x = va[k-1];
	y = vb[b-m];
	if (x < y) printf ("YES\n");
	else printf ("NO\n");
}