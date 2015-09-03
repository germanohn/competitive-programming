#include <cstdio>
#include <algorithm>
#define MAX 10002

using namespace std;

int p, s, ini, fim, cont = 1;

bool compara (pair<int, int> x, pair<int, int> y) {
	return x.first < y.first;
}

int main () {
	pair<int, int> inter[MAX];
	for (int i = 0; scanf ("%d %d", &p, &s) && p != 0 && s != 0; i++) {
		for (int i = 0; i < s; i++)
			scanf ("%d%d", &inter[i].first, &inter[i].second);
		sort (inter, inter + s, compara);
		ini = inter[0].first, fim = inter[0].second;
		printf ("Teste %d\n", cont++);
		for (int i = 1; i < s; i++) {
			if (fim >= inter[i].first) {
				if (fim < inter[i].second)
					fim = inter[i].second;
			}
			else {
				printf ("%d %d\n", ini, fim);
				ini = inter[i].first;
				fim = inter[i].second;
			}
		} 
		printf ("%d %d\n\n", ini, fim);
	}
}