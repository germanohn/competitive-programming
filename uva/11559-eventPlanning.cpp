#include <bits/stdc++.h>
using namespace std;

int n, b, h, w;
int d[15];

int main () {
    while (scanf ("%d%d%d%d", &n, &b, &h, &w) != EOF) {
        int cost = INT_MAX, price;
        for (int i = 0; i < h; i++) {
            scanf ("%d", &price);
            for (int j = 0; j < w; j++) {
                scanf ("%d", &d[j]);
            }
            sort (d, d+w);
            if (b/price >= n && d[w-1] >= n) {
                if (n*price < cost) {
                    cost = n*price;
                }
            } 
        }
        if (cost == INT_MAX) printf ("stay home\n");
        else printf ("%d\n", cost);
    }

}
