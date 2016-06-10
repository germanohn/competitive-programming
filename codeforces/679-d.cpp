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

const ll MAX = 1e5 + 5;

ll m;
ll cubo[MAX];

int main () {
    cin >> m;
    for (ll i = 1; i <= 1e5; i++) 
        cubo[i] = i*i*i;
    // primeiro tenho que maximizar o numero de numeros usados
    // vou ver quantos usa pra cada valor 
    for (ll i = m; i >= 1; i--) {
        ll tmp = i;
        ll qtd = 0;
        while (tmp > 0) {
            ll lo, hi;
            lo = 1, hi = 1e5;
            while (lo != hi) {
                ll mid = (lo+hi)/2;
                if (cubo[mid] > tmp)
                    hi = mid;
                else 
                    lo = mid+1;
            }
            tmp -= cubo[lo-1];
            qtd++;
            //printf ("i %lld tmp %lld\n", i, tmp);
        }
        printf ("i %lld qtd %lld\n", i, qtd);
    }
}

