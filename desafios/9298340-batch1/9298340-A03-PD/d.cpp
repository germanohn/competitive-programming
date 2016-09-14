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

const int MAX = 200005;
const int MOD = 1000000007;

int pot[MAX], d[MAX];

ll fexp (ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return fexp ((x*x) % MOD, y/2) % MOD;
    return (x*fexp ((x*x) % MOD, y/2)) % MOD;
}

int main () {
    int m;
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &d[i]);
        pot[d[i]]++;
    }
    ll ans = 1;
    bool first = false, ok = false;
    for (int i = 2; i < MAX; i++) if ((pot[i]+1) % 2 == 0) ok = true;
    for (int i = 2; i < MAX; i++) {
        if (pot[i] > 0) {
            int expo = pot[i];
            if (!ok && expo % 2 == 0) expo /= 2;
            ans = (ans * fexp (i, expo)) % MOD;
        }
    }
    for (int i = 2; i < MAX; i++) {
        if (pot[i] > 0) {
            int expo = pot[i] + 1;
            if (ok && !first && expo % 2 == 0) expo /= 2, first = true; 
            ans = fexp (ans, expo); 
        }
    }
    printf ("%lld\n", ans);
}

