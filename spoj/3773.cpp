#include <cstdio>
#include <map>

using namespace std;

int main () {
	int n, ind = 0, maior = 0;
	scanf ("%d", &n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a;
		scanf ("%d", &a);
		if (m.find(a) != m.end()) m[a]++;
		else m[a] = 1;
		if (maior < m[a]) {
			maior = m[a];
			ind = a;
		}
	}
	printf ("%d\n", ind);
}	