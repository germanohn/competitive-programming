#include <cstdio>
#include <algorithm>
using namespace std;

long long a, b, cont;

int main () {
    while (scanf ("%lld %lld", &a, &b) && a != 0 && b != 0) {
        cont = 0;
        if (a < b) swap (a, b);
        if (b == 0) {
            printf ("Stan wins\n");
            continue;
        }
       
        while (1) {
            if (a == b || a >= 2*b) {
                printf ("%s wins\n", cont%2==0 ? "Stan" : "Ollie");
                break;
            }
            a %= b;
            swap (a, b);
            cont++;
        }
    }
}
