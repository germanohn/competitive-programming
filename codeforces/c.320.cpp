#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int main () {
    scanf ("%d %d", &a, &b);
    if (a < b) printf ("-1\n");
    else printf ("%.12f\n", (a+b)/(2*((a*b)/(2*b))));
}
