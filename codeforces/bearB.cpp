#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#define MAX 4010

using namespace std;

int n, m, a, b;
struct tipo {
	set<int> conhe;
};

tipo tree[MAX], leaf[MAX];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &a, &b);
		tree[a].conhe.insert (b);
		tree[b].conhe.insert (a);
	}
	printf ("\n");
	set<int> ::iterator it;
	for (int i = 1; i <= n; i++) {
		printf ("%d ", i);
		for (it = tree[i].conhe.begin (); it != tree[i].conhe.end (); it++) {
			printf ("%d ", *it);
		}
		printf ("\n\n");
	}

}
