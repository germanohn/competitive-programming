#include <cstdio>
#include <cmath>
#define EPS 1e-9

using namespace std;

int k1, k2, x, y, g = 10, v;
double ang;

double calc (double angulo) {
	x = (v*v*sin (2*angulo))/g;
	y = (v*v*sin (angulo)*sin (angulo))/(2*g);
	return (k1*x + k2*y);
}

double melhor (int v) {
	double m ,l = 0, r = (acos (-1))/2;
	while (r - l > EPS) {
		m = (double) (l+r)/2;
		if (calc (r) > calc (l)) {
			ang = r;
			l = m;
		}
		else {
			ang = l;
			r = m;
		}
	}
	return calc (r);
}

int main () {
	int n;
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d %d %d", &v, &k1, &k2);
		printf ("%.3lf %.3lf\n", ang, melhor (v));
	}
}