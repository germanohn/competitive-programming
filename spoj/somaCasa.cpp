#include <bits/stdc++.h>

int n, v[100005], lo, hi, mid;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    int soma;
    scanf ("%d", &soma);
    for (int i = 0; i < n; i++) {
        int pro = v[i];
        lo = 0, hi = n - 1;
        while (lo != hi) {
            mid = (lo + hi + 1) / 2;
            if (v[mid] + pro == soma)
                break;
            else if (v[mid] + pro < soma) lo = mid;
            else if (v[mid] + pro > soma) hi = mid - 1;
        }
        if (lo != hi) {
            printf ("%d %d\n", v[i], v[mid]); 
            break;
        }
    }
}
