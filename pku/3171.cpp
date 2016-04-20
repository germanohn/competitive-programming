#include <cstdio>
#include <algorithm>
#include <cstring>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1000000000;
const int MAX = 100005;

struct interval {
    int t1, t2, s;
};

int n, m, e;
int dp[MAX];
interval inter[MAX];

bool cmp (interval a, interval b) {
	return a.t2 > b.t2;
}

int main () {
    scanf ("%d %d %d", &n, &m, &e);
    for (int i = 0; i < n; i++) 
        scanf ("%d %d %d", &inter[i].t1, &inter[i].t2, &inter[i].s);
	// ordena pelo fim
    sort (inter, inter+n, cmp);
	// dp bottom-up
	for (int i = 0; i < n; i++) {
		if (inter[i].t2 == e) {
			dp[i] = inter[i].s;
			continue;
		}
		int ans = inf;
		for (int j = 0; j < i; j++) {
			if (inter[i].t2 >= inter[j].t1-1)
				ans = min (ans, inter[i].s + dp[j]);
		}
		dp[i] = ans;
	}
	int ans = inf;
	// pega o minimo dos intervalos que comecam em m
	for (int i = 0; i < n; i++)
		if (inter[i].t1 == m)
			ans = min (ans, dp[i]);
	if (ans == inf)
		printf ("-1\n");
	else 
		printf ("%d\n", ans);
}

