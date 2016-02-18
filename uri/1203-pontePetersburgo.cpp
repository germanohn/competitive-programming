#include <bits/stdc++.h>
using namespace std;

int k, r;
int gr[110], me[110][10100];

bool dp (int i, int s) {
    if (me[i][s] != -1) return me[i][s];
    if (i == r + 1 || s > k) return me[i][s] = 0;
    if (s == k) return me[i][s] = 1; 
    return me[i][s] = dp (i + 1, s) + dp (i + 1, s + gr[i+1]);
}

int main () {
    while (scanf ("%d %d", &r, &k) != EOF) {
        memset (me, -1, sizeof (me));
        memset (gr, 0, sizeof (gr));
        int a, b;
        for (int i = 0; i < k; i++) {
            scanf ("%d %d", &a, &b);
            gr[a]++, gr[b]++;
        }
        /*for (int i = 1; i <= r; i++)
            printf ("%d ", gr[i]);
        printf ("\n");
        */if (dp (1, 0)) 
            printf ("S\n");
        else printf ("N\n");
    } 
    return 0;
}
