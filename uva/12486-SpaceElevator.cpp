#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int llu;

llu n, ans;
int cont;
llu me[20][10][2][2]; 
char str[20];

llu dp (int i, int ult, bool pre, bool f) {
    if (str[i] == 0) {
        if (f) {
            printf ("cont %d\n", cont++);
            return 1;
        }
        printf ("ult %d\n", ult);
        return 0;
    }
    
    //if (str[0] == 0 && !f) return 0;
    llu &m = me[i][ult][pre][f];
    if (m != -1) return m;
    m = 0;
    for (int d = 0; d <= 9; d++) {
        f = true;
        if (pre && d > str[i]-'0') break;
        if (d == 4 || (ult == 1 && d == 3) || (i == 0 && d == 0)) {
            printf ("passei pelo falso\n");
            f = false;
        }
        m += dp (i+1, d, pre && d == str[i]-'0', f);
        printf ("m %llu\n", m);
    }
    printf ("i %d m %llu\n", i, m);
    return m;
} 

int main () {
    while (scanf ("%llu", &n) != EOF) {
        cont = 0;
        sprintf (str, "%llu", n);
        printf ("str %s\n", str);
        memset (me, -1, sizeof (me));
        ans = dp (0, 0, true, true);
        printf ("%llu\n", ans);
    }
}
