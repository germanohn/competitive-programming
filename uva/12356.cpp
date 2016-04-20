#include <bits/stdc++.h>
#define l first
#define r second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 112345;

int s, b, x, y;
pii v[MAX];

int main () {
	while (scanf ("%d %d", &s, &b) && s != 0 && b != 0) {
		v[0].l = -1;
		v[0].r = 1;
		v[s-1].l = s-2;
		v[s-1].r = -1;
		for (int i = 1; i < s-1; i++) {
			v[i].l = i-1;
			v[i].r = i+1;
		}
		for (int i = 0; i < b; i++) {
			scanf ("%d %d", &x, &y);
			x--, y--;
			int esqX = v[x].l;
			int dirY = v[y].r;
			if (esqX != -1) {
				v[esqX].r = dirY;
				printf ("%d ", esqX+1);
			} else {
				printf ("* ");
			}
			if (dirY != -1) {
				v[dirY].l = esqX;
				printf ("%d\n", dirY+1);
			} else {
				printf ("*\n");
			}
		}
		printf ("-\n");
	}
}

