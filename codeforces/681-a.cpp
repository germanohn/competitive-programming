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

int n;

int main () {
    scanf ("%d", &n);
    bool f = false;
    char name[15];
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf (" %s %d %d", name, &a, &b);
        if (a >= 2400 && b > a) 
            f = true;
    }
    if (f) 
        printf ("YES\n");
    else 
        printf ("NO\n");
}

