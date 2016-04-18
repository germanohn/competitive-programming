#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 11234;

int test, n, t, m, a, lIni, rIni, lFim, rFim;
char s[10];
pii l[MAX], r[MAX];
vector<pii> ans;

int main () {
	scanf ("%d", &test);
	while (test--) {
		rIni = lIni = lFim = rFim = 0;
		scanf ("%d %d %d", &n, &t, &m);
		for (int i = 0; i < m; i++) {
			scanf ("%d %s", &a, s);
			if (s[0] == 'l') { 
				l[lFim].ff = a;
				l[lFim++].ss = i;
			}
			else { 
				r[rFim].ff = a;
				r[rFim++].ss = i;
			}
		}
		bool left = true;
		int cont = 0, tempo = 0;
		while (cont < m) {
			int q = 0;
			if (l[lIni].ff > tempo && r[rIni].ff > tempo) {
				if (l[lIni].ff < r[rIni].ff) {
					tempo = l[lIni].ff;
					if (left)
						continue;
					left = true;
				}
				else if (l[lIni].ff > r[rIni].ff) {
					tempo = r[rIni].ff;
					if (!left)
						continue;
					left = false;
				}
			}
			if (left) {
				//if (l[lIni].ff > tempo)
				//	tempo = l[lIni].ff;
				while (q < n && lIni != lFim && l[lIni].ff <= tempo) {
					q++;
					ans.pb (pii (l[lIni].ss, tempo+t));
					lIni++;		
				}
				cont += q;
				if (q != 0) left = false;
			} else {
				//if (r[rIni].ff > tempo)
				//	tempo = r[rIni].ff;
				printf ("oi\n");
				while (q < n && rIni != rFim && r[rIni].ff <= tempo) {
					q++;
					ans.pb (pii (r[rIni].ss, tempo+t));
					rIni++;
				}
				cont += q;
				if (q != 0) left = true;
			}
			tempo += t;
		}
		sort (ans.begin (), ans.end ());
		for (int i = 0; i < m; i++) 
			printf ("%d\n", ans[i].ss);
		printf ("\n");
		ans.clear ();
	}
}

