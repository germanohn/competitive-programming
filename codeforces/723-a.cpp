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

int main () {
    int a, b, c;
    scanf ("%d %d %d", &a, &b, &c);

    int ans = 305, aux;
    for (int i = 1; i <= 100; i++) {
        aux = 0;
        aux += abs (i-a) + abs (i-b) + abs (i-c);
        if (aux < ans) ans = aux;
    }

    printf ("%d\n", ans);
}

