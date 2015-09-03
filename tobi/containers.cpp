#include <cstdio>

using namespace std;

int a, b, c, x, y, z;

int main () {
	scanf ("%d%d%d %d%d%d", &a, &b, &c, &x, &y, &z);
	int max = (x/a)*(y/b)*(z/c);
	printf ("%d\n", max);
}