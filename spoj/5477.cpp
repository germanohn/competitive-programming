#include <cstdio>
#include <algorithm>
#include <set>
#define MAX 10005
using namespace std;

int main () {
	int a, b, aux;
	set<int> ali, bea;
	while (scanf ("%d%d", &a, &b) && a != 0 && b != 0) {
		for (int i = 0; i < a; i++){
			scanf ("%d", &aux);
			ali.insert (aux);
		}
		for (int i = 0; i < b; i++){
			scanf ("%d", &aux);
			bea.insert (aux);
		}
		set<int>::iterator it;
		int cont_a = 0, cont_b = 0;
		for (it = ali.begin (); it != ali.end (); it++) {
			if (bea.find (*it) == bea.end ())
				cont_a++;
		}
		for (it = bea.begin (); it != bea.end (); it++) {
			if (ali.find (*it) == ali.end ())
				cont_b++;
		}
		if (cont_a < cont_b) printf ("%d\n", cont_a);
		else printf ("%d\n", cont_b);
		ali.clear ();
		bea.clear ();
	}
}