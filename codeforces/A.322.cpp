#include <bits/stdc++.h>
using namespace std;

int a, b, dif, same;

int main () {
    scanf ("%d %d", &a, &b);
    if (a > b) {
        dif = b;
        a -= b;
        same = a/2;
    }
    else {
        dif = a;
        b -= a;
        same = b/2;
    }
    printf ("%d %d\n", dif, same);
}
