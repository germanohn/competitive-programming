#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAXN = 100;

ll n;
ll prime[MAXN], p[MAXN];

pll solve (int i, int e, ll pot, ll qtd_div) {
    ll nx_pot = prime[i];
    pll ans = pll (qtd_div, pot);
    for (ll exp = 1; exp <= e && pot <= n/nx_pot; exp++) {
        pll tmp = solve (i+1, exp, pot*nx_pot, qtd_div * (exp+1));
        nx_pot *= prime[i];
        if (tmp.ff > ans.ff || (tmp.ff == ans.ff && tmp.ss < ans.ss)) ans = tmp;
    }
    return ans;
}

void sieve () {
    for (int i = 2; i < MAXN; i++) 
        if (!p[i]) {
            for (int j = i+i; j < MAXN; j += i) 
                p[j] = i;
        }
    int k = 0;
    for (int i = 2; i < MAXN; i++) 
        if (!p[i]) prime[k++] = i;
}   

int main () {
    sieve ();
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%lld", &n);
        ll pot = 1;
        pll ans = pll (1, 1);
        for (int exp = 1; pot <= n/prime[0]; exp++) {
            pot *= prime[0];
            pll tmp = solve (1, exp, pot, exp+1);
            if (tmp.ff > ans.ff || (tmp.ff == ans.ff && tmp.ss < ans.ss)) ans = tmp;
        } 
        printf ("%lld %lld\n", ans.ss, ans.ff);
    }
}

