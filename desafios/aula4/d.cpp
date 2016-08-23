#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

ll fexp (ll b, ll e, ll mod) {
    if (e == 0) return 1;
    if (e == 1) return b % mod;
    if (e % 2 == 0) return fexp (b*b % mod, e/2, mod) % mod;
    return (b * fexp (b*b % mod, e/2, mod)) % mod;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, p, q;
        scanf ("%d", &n);
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                p = i, q = n/i;
                break;
            }   
        }
        int phi = (p-1)*(q-1);
        printf ("0 1 ");
        int a, b;
        a = (p * fexp (p % q, phi-1, q)) % n;
        b = (q * fexp (q % p, phi-1, p)) % n;
        if (a > b) swap (a, b);
        printf ("%d %d\n", a, b);
    }
}

