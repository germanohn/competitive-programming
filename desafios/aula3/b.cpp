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

const int MAX = 100005;

int phi[MAX], p[MAX];
ll ans[MAX];

void sieve () {
    for (int i = 2; i*i < MAX; i++) {
        if (!p[i]) {
            for (int j = i*i; j < MAX; j += i)
                p[j] = i;
        }
    }
}

int main () {
    int t, n;
    scanf ("%d", &t);
    sieve ();
    for (int i = 2; i < MAX; i++) 
        if (!p[i]) p[i] = i;
    for (int i = 1; i < MAX-1; i++) {
        int aux = i, a, b = 1;
        phi[i] = 1;
        while (aux > 1) {
            a = 1;
            int div = p[aux];   
            while (aux > 1 && aux % div == 0) {
                a *= div;
                aux /= div; 
            }
            b = a/div;
            phi[i] *= (a-b);
        }
    }
    ans[0] = 0;
    for (int i = 1; i < MAX; i++) 
        ans[i] = ans[i-1] + (i-phi[i]);
    int cont = 1;
    while (t--) {
        scanf ("%d", &n);
        printf ("Case %d: %lld\n", cont++, ans[n]);
    }
}

