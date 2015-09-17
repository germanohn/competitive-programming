#include <bits/stdc++.h>
#define MAX 1005 

using namespace std;

int x, y, n, w, t;
double px, py, memo[MAX][10005], a, b;

double pd (int quant, int pto) {
    if (quant == 0) {
        printf ("pto %d\n", pto);
        if (pto >= w) return 1;
        else return 0;
    }
    if (memo[quant][pto] != -1) return memo[quant][pto];
    a = px * pd (quant - 1, pto + x);
    b = py * pd (quant - 1, pto + y);
    return memo[quant][pto] = max (a, b); 
}

int main () {
    while (scanf ("%d", &t) != EOF) {
        scanf ("%d %d %d %d %lf %lf", &x, &y, &n, &w, &px, &py);
        px /= 100;
        py /= 100;
        printf ("oi\n");
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			memo[i][j] = -1;
		}
	}
        printf ("%lf\n", pd (n, 0));
    }
}
