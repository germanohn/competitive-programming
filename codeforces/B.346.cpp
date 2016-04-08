#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a, b;

int main () {
    scanf ("%d %d %d", &n, &a, &b);
    if (b < 0) {
        int aux = b*(-1);
        aux %= n;
        b = n-aux;
    } else {
        b %= n;
    }
    if ((a+b)%n == 0)
        printf ("%d\n", n);
    else 
        printf ("%d\n", (a+b)%n);
}

