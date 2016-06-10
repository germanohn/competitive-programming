#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const ll A = 1e18;

int t, n, ans;
ll a;
vector<pli> v;

int main () {
    for (ll i = 1; i <= A; i *= 12) 
        v.pb (mp (i, 1));
    for (ll i = 2; i <= A; i *= 12) 
        v.pb (mp (i, 2));
    for (ll i = 4; i <= A; i *= 12) 
        v.pb (mp (i, 3));
    v.pb (mp (0, 0));
    for (ll i = 6; i <= A; i *= 12) 
        v.pb (mp (i, 0));

    sort (v.begin (), v.end ());
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%lld", &a);
            int pos = upper_bound (v.begin (), v.end (), pli (a, 5)) - v.begin () - 1;
            ans ^= v[pos].ss;
        }    
        if (ans == 0) {
            printf ("Derek\n");
        } else {
            printf ("Henry\n");
        }
    }
}

