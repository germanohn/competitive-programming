#include <cstdio>
#include <algorithm>
#define MAX 100005

using namespace std;

struct gas {
	double pre�o, estoq;
};

bool compara (gas x, gas y) {
	return x.pre�o < y.pre�o;
}

gas forn[MAX];

int n;
double d, custo;

int main () {
	scanf ("%d %lf", &n, &d);
	for (int i = 0; i < n; i++) scanf ("%lf %lf", &forn[i].pre�o, &forn[i].estoq);
	sort (forn, forn + n, compara);
	for (int i = 0; i < n; i++) {
		gas davez = forn[i];
		if (a.first < d) {
			d -= davez.estoq;
			custo += davez.estoq*davez.pre�o;
		}
		else {
			custo += davez.pre�o*d;
			d = 0;
			break;
		}
	}
	if (d) printf ("Imposs�vel\n");
	else printf ("%d\n", custo);
}
