#include <bits/stdc++.h>

using namespace std;

int n, m, c;

int main () {
    while (scanf ("%d %d %d", &n, &m, &c) && n != 0) {
        n -= 7;
        m -= 7;
        int ans;
        ans = (n*m + 1) / 2;
        if (n % 2 == 0 || m % 2 == 0) 
            printf ("%d\n", ans);
        else {
            if (c == 0)
                printf ("%d\n", ans-1);
            else 
                printf ("%d\n", ans);
        }
    }
}
