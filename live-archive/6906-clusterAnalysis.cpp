#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;

int t, n, k;
int v[MAX];

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while(t--) {
        scanf ("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }
        sort (v, v+n);
        int quant = 1, atu, ant = v[0];
        for (int i = 1; i < n; i++) {
            atu = v[i];
            if (atu-ant > k) quant++;
            ant = atu;
        }
        printf ("Case #%d: %d\n", cont++, quant);
    }
}
