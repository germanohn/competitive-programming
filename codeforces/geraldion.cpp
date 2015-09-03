#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1005

using namespace std;

int main () {
	vector<int> seq;
	int n;
	scanf ("%d", &n);	
	for (int i = 0; i < n; i++) {
		int a;
		scanf ("%d", &a);
		seq.push_back (a);
	}
	sort (seq.begin (), seq.end ());
	if (seq[0] == 1) printf ("-1\n");
	else printf ("1\n");
}