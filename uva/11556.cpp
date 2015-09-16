#include <bits/stdc++.h>

using namespace std;

long long int n, b, num;

int main () {
	scanf ("%lld %lld", &n, &b);
	if (num == 1) printf ("yes\n");
	num = pow (2, b + 1) - 2;
	if (num > n) printf ("yes\n");
	else printf ("no\n");
}
