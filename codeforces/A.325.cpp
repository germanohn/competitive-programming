#include <bits/stdc++.h>
using namespace std;

int n, v[105], apa[105];

int main () {
    scanf ("%d", &n);
    int k = 0, ans = n;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    int quant = 0; 
    for (int i = 0; i < n; i++) {
        if (v[i] == 1)
            break;
        quant++;
        k = i;
    }
    k++;
    ans -= quant;
    quant = 0;
    for (int i = k; i < n; i++) {
        if (v[i] == 1) {
            if (quant >= 2)
                ans -= quant;
            quant = 0;
        }
        else
            quant++;
    }
    ans -= quant;
    printf ("%d\n", ans);
}
