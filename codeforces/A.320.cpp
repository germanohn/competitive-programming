#include <bits/stdc++.h>

using namespace std;

int n, cont;

int primo (int num) {
    while (num != 1) {
        if (num % 2 != 0) {
            cont++;
            num--;
        }
        num /= 2;
    } 
    return cont + 1;
}

int main () {
    scanf ("%d", &n); 
    printf ("%d\n", primo (n));
}
