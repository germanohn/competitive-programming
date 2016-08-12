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

const int MAX = 10005;

int pot[MAX], p[MAX];

void sieve () {
    for (int i = 2; i*i < MAX; i++) {
        if (!p[i]) {
            for (int j = i*i; j < MAX; j += i)
                p[j] = i;
        }
    }
}

int main () {
    sieve ();
    for (int i = 2; i < MAX; i++)
        if (!p[i]) p[i] = i;
    for (int i = 0; i < 10; i++) {
        int a;
        scanf ("%d", &a);
        while (a > 1) {
            pot[p[a]]++;
            a /= p[a];
        }
    }
    int ans = 1;
    for (int i = 2; i < MAX; i++) 
        ans = (ans*(pot[i]+1)) % 10;
    printf ("%d\n", ans);
}

