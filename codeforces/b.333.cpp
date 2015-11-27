#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n; 
int v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    int ind;
    int ini = 0, fim = 0, k = 0, j = 0, priM = v[0], prim = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] > priM) priM = v[i];
        else if (v[i] < prim) {
            prim = v[i];
            ind = i;
        }
        if (priM - prim > 1) {
            k = ind+1;
            prim = v[k];
            priM = v[k];
        } 
        else {
            j = i;
            if (fim - ini < j - k) {
                ini = k;
                fim = j;
            }
        }
        printf ("prim %d priM %d\n", prim, priM);
    }
    printf ("ini %d fim %d\n", ini, fim); 
    printf ("%d\n", fim - ini + 1);
}
