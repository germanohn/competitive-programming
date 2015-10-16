#include <bits/stdc++.h>

using namespace std;

int n, d, r, mor[105], eve[105], ans, menor, maior; 

int main () {
    while (scanf ("%d %d %d", &n, &d, &r) && n != 0 && d != 0 && r != 0) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &mor[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf ("%d", &eve[i]);
        }
        sort (mor, mor + n);
        sort (eve, eve + n);
        for (int i = 0; i < n; i++) {
            int a = eve[n-i-1] + mor[i];
            if (d < a)
                ans += (a - d) * r;
        }
        printf ("%d\n", ans);
    }
}
