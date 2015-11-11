#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;

llu n, ans;
llu me[20][10][2][2]; 
char str[20];

llu dp (int i, int ult, bool pre, bool f) {
    if (str[i] == 0) return f; 
    llu &m = me[i][ult][pre][f];
    if (m != -1) return m;
    m = 0;
    bool aux = false;
    for (int d = 0; d <= 9; d++) {
        aux = false;
        if (pre && d > str[i]-'0') break;
        if (d == 4 || (ult == 1 && d == 3)) {
            aux = true;
        }
        m += dp (i+1, d, pre && d == str[i]-'0', f || aux);
    }
    return m;
} 

int main () {
    while (scanf ("%llu", &n) != EOF) {
        llu e = 0, d = 9330720600916705820;
        while (e != d) {
            llu mid = e + (d-e)/2;
            sprintf (str, "%llu", mid);
            memset (me, -1, sizeof (me));
            llu quant = dp (0, 0, true, false);
            if (mid - quant >= n) 
                d = mid;
            else 
                e = mid+1;
        }
        printf ("%llu\n", e);
    }
}
