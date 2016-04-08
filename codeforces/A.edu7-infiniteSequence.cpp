#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

//O(n)
/*int main () {
    ll n, k;
    cin >> n; 
    ll num = sqrt (1 + 8*n);
    if (num * num == 1 + 8*n) 
        k = sqrt (1 + 8*n)/2;
    else k = (sqrt (1 + 8*n)+1)/2;
    n = n - ((k-1)*k)/2;
    cout << n << endl;
}*/

//O(raiz n)
int main () {
    ll n, ant, cont;
    cin >> n;
    cont = 1;
    while (n > 0) {
        ant = n;
        n -= cont;
        cont++;
    }
    cout << ant << endl;
}

