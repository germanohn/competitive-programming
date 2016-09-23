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

const int MAX = 100;

int n;

int main () {
    scanf (" %d", &n);
    int ant, atual;
    scanf (" %d", &ant);
    for (int i = 0; i < n-1; i++) {
        scanf (" %d", &atual);
        if (i != n-2) ant = atual;
    }

    if (n == 1) atual = ant;
    if (atual == 0) {
        printf ("UP\n");
    } else if (atual == 15) {
        printf ("DOWN\n");
    } else if (n == 1) {
        printf ("-1\n");
    } else {
        if (ant < atual) printf ("UP\n");
        else printf ("DOWN\n");
    }
}

