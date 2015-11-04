#include <bits/stdc++.h>
using namespace std;

int n, fi;

int main () {
    while (scanf ("%d", &n) != EOF) {
        fi = 1;
        for (long long i = 2; i * i <= n; i++) {
            bool f = false;
            while (n % i == 0) {
                n /= i;
                fi *= i;
                f = true;
            } 
            if (f) {
                fi /= i;
                fi *= (i-1);
            }
            
        }
        if (n > 1) fi *= (n-1);
        printf ("%d\n", fi/2);
    }
}
