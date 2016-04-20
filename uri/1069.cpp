#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int t, ans, top;
char p[MAX], s[MAX];

int main () {
	scanf ("%d", &t);
	while (t--) {
		top = 0, ans = 0;
		scanf ("%s", s);
		for (int i = 0; s[i] != 0; i++) {
			if (s[i] == '<') {
				p[top++] = '<';
			} else if (s[i] == '>') {
				if (p[top-1] == '<') {
					top--;
					ans++;
				} else {
					p[top++] = '>';
				}
			}
		}
		printf ("%d\n", ans);
	}
}

