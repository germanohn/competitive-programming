#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int v[MAX];

int main () {
    int n, quad = 1, i = 1, ind;
    scanf ("%d", &n);
    while (quad <= 100000) {
        v[i] = quad;
        i++, quad *= 2;
    }
    v[i] = 100005;
    while (n > 0) {
        ind = lower_bound (v+1, v+i+1, n) - v;
        //printf ("v ind %d ind %d\n", v[ind], ind);
        if (n == 1) {
            n -= v[ind];
            printf ("1 ");
        }
        else if (n % v[ind] != 0) {
            n -= v[ind-1];
            printf ("%d ", ind-1);
        }
        else {
            n -= v[ind];
            printf ("%d ", ind);
        }
    }
    printf ("\n");
}
