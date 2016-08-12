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

int gcd (int x, int y) {
    if (y == 0) return x;
    return gcd (y, x%y);
}

int main () {
    int t, a, b, c, d;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d %d %d", &a, &b, &c, &d);
        int ans;
        int x = c-a;
        int y = d-b;
        ans = abs (gcd (x, y)) + 1;
        printf ("%d\n", ans);
    }
}

