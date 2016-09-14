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

const int inf = 2147483647;

set<int> s;

int main () {
    int n;
    scanf ("%d", &n);
    ll num = 1;
    int razao = 1;
    s.insert (num);
    while (num <= inf) {
        num += razao;
        razao++;
        s.insert (num);
    }
    while (n--) {
        int a;
        scanf ("%d", &a);
        if (s.find (a) == s.end ()) printf ("0 ");
        else printf ("1 ");
    }
    printf ("\n");
}

