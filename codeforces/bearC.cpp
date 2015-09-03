#include <cstdio>
#include <set>
#define MAX 100010

using namespace std;

int n, poker[MAX];
set<int> p;

int divide (int n) {
	while (n % 2 == 0)
		n /= 2;
	while (n % 3 == 0)
		n /= 3;
	return n;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &poker[i]);
	}
	for (int i = 0; i < n; i++) 
		p.insert (divide (poker[i]));
	if (p.size () == 1)
		printf ("Yes\n");
	else printf ("No\n");
}