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

ll fexp (ll b, ll e, ll m) {
    if (e == 0) return 1 % m;
    if (e == 1) return b % m;
    if (e % 2 == 0) return (fexp (b*b % m, e/2, m)) % m;
    return (b * fexp (b*b % m, e/2, m)) % m;
}

int main () {
    int t;
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        int b, m;
        ll e;
        scanf ("%d %lld %d", &b, &e, &m);
        printf ("%d. %d\n", cont++, fexp (b, e, m) % m);
    }
}

