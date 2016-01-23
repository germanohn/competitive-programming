#include <bits/stdc++.h>
using namespace std;

int main () {
    int x;
    scanf ("%d", &x);
    if (x <= 5) {
        printf ("1\n");
    }
    else {
        int quant = x/5;
        if (x%5 == 0) printf ("%d\n", quant);
        else printf ("%d\n", quant+1);
    }
}
