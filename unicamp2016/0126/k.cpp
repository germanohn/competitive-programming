#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, s = 0, g = 0, e = 0, aux;
    float media = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &aux);
        if (aux == 3) s++;
        else if (aux == 4) g++;
        else if (aux == 5) e++;
        media += aux;
    }
    media /= n;
    if (s > 0) printf ("None\n");
    else if (e == n) printf ("Named\n");
    else if (media >= 4.5) printf ("High\n");
    else printf ("Common\n");
}

