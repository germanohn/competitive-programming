#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, top;
char c, p[150];

int main () {
	scanf ("%d", &t);
	while (t--) {
		top = 0;
		getchar ();
		int cont = 0;
		while ((c = getchar ()) && c != '\n') {
			cont++;
			printf ("cont %d\n", cont);
			if (c == '(' || c == '[') {
				p[top++] = c;
			} else if (c == ')') {
				if (p[top-1] == '(')
					top--;
				else 
					p[top++] = c;
			} else if (c == ']') {
				if (p[top-1] == '[')
					top--;
				else 
					p[top++] = c;
			}
		}
		if (top == 0) printf ("Yes\n");
		else printf ("No\n");
	}
}

