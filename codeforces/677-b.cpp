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

ll n, h, k;
ll v[100005];

int main () {
    cin >> n >> h >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll tempo = 0, in = 0;
    int i = 0;
    while (1) {
        while (in+v[i] <= h && i < n) {
            in += v[i];
            i++;
        }
        if (i == n) {
            tempo += (ll) (in+k-1)/k;
            break;
        }
        ll falta = (ll) h-in;
        ll tmp = (v[i]-falta+k-1)/k;
        tempo += tmp; 
        in -= k*tmp;
        if (in < 0) 
            in = 0;
    }
    cout << tempo << "\n";

}

