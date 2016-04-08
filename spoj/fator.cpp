#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
#define MAX 10000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll ult[1000005];

ll pri (ll dig) {
    while (dig % 10 == 0) 
        dig /= 10;
    return dig;
}

int main () {
    ll dig = 1;
    for (ll x = 1; x <= 1000000; x++) {
        dig = dig*x;
        dig = (pri (dig)) % MAX;
        ult[x] = dig%10;
    }
    int n, cont = 1;
    while (scanf ("%d", &n) != EOF) {
        printf ("Instancia %d\n%lld\n\n", cont++, ult[n]);
    }
}

