#include <bits/stdc++.h>

using namespace std;

int b, n, d, c, v, res[25];

int main () {
    while (scanf ("%d %d", &b, &n) && b != 0 && n != 0) {
        bool f = true;
        for (int i = 1; i <= b; i++) 
            scanf ("%d", &res[i]);
        for (int i = 0; i < n; i++) {
            scanf ("%d %d %d", &d, &c, &v);
            res[d] -= v;
            res[c] += v;
        }
        for (int i = 1; i <= b; i++) {
            if (res[i] < 0) {
                printf ("N\n");
                f = false;
                break;
            }
        }
        if (f) printf ("S\n");
        
    }
}
