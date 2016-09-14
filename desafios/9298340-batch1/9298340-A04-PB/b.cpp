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

const int MAX = 1000005;

int p[MAX], pri[MAX], ans;

void sieve () {
    for (ll i = 2; i < MAX; i++) {
        if (!pri[i]) {
            pri[i] = i;
            for (ll j = i*i; j < MAX; j += i) 
                pri[j] = i;
        }
    }
}

void init () {
    p[1] = 0;
    for (int i = 2; i < MAX; i++) {
        int aux = i;
        if (pri[i] == i) {
            p[i] = -1;
            continue;
        }
        while (aux > 1) {
            aux /= pri[aux];
            p[i]++;
        }
    }
}

void kadane (int l, int r) {
    int aux = 0;
    ans = -10;
    for (int i = l; i <= r; i++) {
        aux += p[i]-1;
        ans = max (ans, aux);
        if (aux < 0) aux = 0;
    }
}

int main () {
    sieve ();
    init ();
    int l, r, cont = 1;
    while (scanf ("%d %d", &l, &r)) {
        if (l == -1 && r == -1) break;
        printf ("%d. ", cont++);
        kadane (l, r);
        printf ("%d\n", ans);
    }
}
/*
int main () {
    sieve ();
    init ();
    int l, r;
    while (scanf ("%d %d", &l, &r)) {
        if (l == -1 && r == -1) break;   
        int ans, aux, tira, end, ganho, l_aux;
        ans = 0, tira = 0, end = min (r, l+10);
        for (int i = l; i <= end; i++) {
            if (pri[i] == i) tira += 2;
            else tira -= (p[i]+1);
            if (aux <= -1) break;
            if (aux > ans) ans = aux, l_aux = i;
            printf ("tira %d\n", tira);
        }
        printf ("l %d r %d ans %d tira %d\n", l, r, ans, tira);
        ganho = ans, ans = 0, tira = 0;
        end = max (l, r-10);
        printf ("end %d\n", end);
        for (int i = r; i >= end; i--) {
            if (pri[i] == i) tira += 2;
            else tira -= (p[i]+1);
            if (aux <= -1) break;
            if (aux > ans) ans = aux, r = i;
        }
        printf ("l %d r %d ans %d tira %d\n", l, r, ans, tira);
        l = l_aux;
        ganho += ans;
        printf ("ganho %d\n", ganho);
        ans = acc[r]-acc[l-1]+ganho-r+l-1;
        printf ("%d\n", ans);
    }
}
*/
