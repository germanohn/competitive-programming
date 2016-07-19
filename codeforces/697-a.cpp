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


int main () {
    int t, s, x;
    scanf ("%d %d %d", &t, &s, &x);
    if (x < t) {
        printf ("NO\n");
    } else if (x > t && x < t+s) {
        printf ("NO\n");
    } else {
        x -= t;
        x %= s;
        if (x == 0 || x == 1) {
            printf ("YES\n");
        } else {
            printf ("NO\n");
        }
    }
}

