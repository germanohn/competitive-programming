#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int llu;

llu n, ans;
int cont;
llu me[20][10][2][2]; 
char str[20];

llu dp (int i, int ult, bool pre, bool f) {
    if (str[i] == 0) return f; 
    
    //if (str[0] == 0 && !f) return 0;
    llu &m = me[i][ult][pre][f];
    if (m != -1) return m;
    m = 0;
    for (int d = 0; d <= 9; d++) {
        f = false;
        if (pre && d > str[i]-'0') break;
        if (d == 4 || (ult == 1 && d == 3)) {
           // printf ("passei pelo falso\n");
            f = true;
        }
        m += dp (i+1, d, pre && d == str[i]-'0', f);
        //printf ("m %llu\n", m);
    }
    //printf ("i %d m %llu\n", i, m);
    return m;
} 

int main () {
    while (scanf ("%llu", &n) != EOF) {
        cont = 0;
        sprintf (str, "%llu", n);
        //printf ("str %s\n", str);
        memset (me, -1, sizeof (me));
        llu e = 0, d = 1000000000000000000;
        while (e != d) {
            llu mid = e + (d-e)/2;
            sprintf (str, "%llu", mid);
            memset (me, -1, sizeof (me));
            llu quant = dp (0, 0, true, false);
            //printf ("quant %llu ", quant);
            if (mid - quant < n) d = mid-1;
            else e = mid;
        }
        printf ("%llu\n", e);
    }
}
