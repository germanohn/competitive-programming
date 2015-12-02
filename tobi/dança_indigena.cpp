#include <cstdio>
#include <algorithm>
#include <set>
#define MAXN 1005
#define MAX 1000005

using namespace std;

int mod (int x, int y) {
	return ((x%y)+y)%y; 
}

int main () {
	int n, e;
	pair<int, int> v[MAXN];
	bool seq[MAX];
	for (int i = 0; i < MAX; i++)
		seq[i] = false; 
	scanf ("%d%d", &n, &e);
	int rta = n;
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		seq[a-1] = true;
		v[i].first = a-1;
		v[i].second = b; 
	}
	sort (v, v + e);
	for (int i = 1; i < e; i++) {
		int dis = v[i].first - v[0].first;
		if (v[i].second == 1)
			dis = n - dis;
		set<int> tree;
		for (int j = 0; j < e; j++) {
			int x;
			x = mod (v[j].first + v[j].second * dis, n);
			//printf("x %d (%d + %d*%d)\n",x,v[j].first,v[j].second,dis);
			if (seq[x]) 
				tree.insert (x);
		}
		if (tree.size () == e) 
			if (dis < rta)
				rta = dis;
	}
	printf ("%d\n", rta);

}
