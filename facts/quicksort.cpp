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

int separa (int l, int r) {
    int pivo = v[l], i = l+1, j = r;
    while (i <= j) {
        if (v[i] <= pivo) i++;
        else if (v[j] > pivo) j--;
        else swap (v[i], v[j]), i++, j--;
    }
    v[l] = v[j], v[j] = pivo;
    return j;
}

void quicksort (int l, int r) {
    if (l < r) {
        int pronto = separa (l, r);
        quicksort (l, pronto-1);
        quicksort (pronto+1, r);
    }
}

