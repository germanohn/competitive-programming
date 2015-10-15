#include <bits/stdc++.h>

using namespace std;

long long int n, b, num;

int main () {
	while (scanf ("%lld %lld", &n, &b) != EOF) {
        num = pow (2, b + 1) - 1;
        if (n <= num) printf ("yes\n");
        else printf ("no\n");    
   }
}
