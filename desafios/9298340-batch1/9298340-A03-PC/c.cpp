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

int p[MAX];

void sieve () {
    for (int i = 2; i*i < MAX; i++) {
        if (!p[i]) {
            for (int j = i*i; j < MAX; j += i)
                p[j] = i;
        }
    }
}

int main () {
    int t, n, k;
    scanf ("%d", &t);
    sieve ();
    for (int i = 2; i < MAX; i++)
        if (!p[i]) p[i] = i;
    while (t--) {
        scanf ("%d %d", &n, &k);
        ll ans = 0;
        int aux = 0, l = 2;
        for (int i = 2; i <= n; i++) {
            if (p[i] == i) aux++;
            while (aux >= k && l <= i) {
                ans += ((ll) n-i+1);
                if (p[l] == l) aux--;
                l++;
            }
        }
        printf ("%lld\n", ans);
    }
}

