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

const int house = 1234567, car = 123456, comp = 1234;
const int MAX = 1e5;

int n;

int main () {
    scanf ("%d", &n);
    bool f = false;
    int a;
    for (int i = 0; !f && i*house <= n; i++) {
        a = i*house;
        for (int j = 0; !f && a + j*car <= n; j++) {
            int tmp = n - a - j*car;
            if (tmp % comp == 0)
                f = true;
        }
    }
    if (f) 
        printf ("YES\n");
    else 
        printf ("NO\n");
}

