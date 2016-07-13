#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

/* ideia: colocar maior x = 9999... e o restante pra somar n */

int main () {
    ll a, b, c;
    scanf ("%lld", &a);
    int sumDig = 0, sumDigB = 0;
    for (ll x = 0; x < a; x = (10*x + 9), sumDigB += 9) {
        int y = a-x;
        int sumDigC = 0;
        while (y) sumDigC += y % 10, y /= 10;
        if (sumDigB + sumDigC > sumDig) {
            sumDig = sumDigB + sumDigC;
            b = x, c = a-x;
        }
    }
    printf ("%d\n%lld %lld\n", sumDig, b, c);
}
