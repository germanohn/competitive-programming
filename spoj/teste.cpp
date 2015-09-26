//veja que pra lo e hi recebendo mid, quando faco mid ser lo + hi sobre 2 ou seja
//o piso, tenho problemas para
#include <bits/stdc++.h>

using namespace std;

int n, v[100], pro, cont, lo, hi, mid;

int main () {
    printf ("entre com n\n");
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    printf ("entre com o numero a ser procurado\n");
    scanf ("%d", &pro);
    lo = 0, hi = n - 1;
    while (lo <= hi) {
        printf ("\n>>cont %d\n", cont);
        mid = (lo + hi + 1) / 2;
        printf ("lo %d hi %d mid %d v[mid] %d pro %d\n", lo, hi, mid, v[mid], pro);
        if (v[mid] == pro) {
            printf ("fim\n");
            break;
        }
        else if (v[mid] > pro) {
            hi = mid - 1;
            printf ("oi\n");
        }
        else if (v[mid] < pro) lo = mid;
        printf ("\n");
        if (cont == 20) break;
        cont++;
    }
}
