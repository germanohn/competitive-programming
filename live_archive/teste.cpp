#include <bits/stdc++.h>
using namespace std;

int main () { 
    srand (time (NULL));
    int n = rand () % 15 + 1;
    int k = rand () % 15 + 1;
    printf ("%d %d\n", n, k);
    for (int i = 0; i < n; i++) {
        int tmp = rand () % 100 + 1;
        printf ("%d%c", tmp, i != n-1 ? ' ' : '\n');
    }
    for (int i = 0; i < k; i++) {
        int tmp = (rand () % 100 + 1);
        int a, b;
        if (tmp % 2 == 0) {
            printf ("C ");
            a = rand () % n + 1;
            b = rand () % 200 + 1 - 100;
        }
        else {
            printf ("P ");
            a = rand () % n + 1;
            b = rand () % n + 1;
        }
        printf ("%d %d\n", a, b);
    } 
}
