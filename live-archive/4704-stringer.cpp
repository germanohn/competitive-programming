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

int n;
ll pr[100005], v[100005], res[100005];

void fatora (ll a, ll tipo) {
    for (ll num = a; num > 0; num--) {
        a = num;
        while (a > 1) {
            if (tipo) res[pr[a]]++;
            else res[pr[a]]--;
            a /= pr[a];
        }
    }
}

void crivo () {
    for (ll i = 2; i <= 100005; i++) {
        if (!pr[i])
            for (ll j = i; j <= 100005; j += i) 
                pr[j] = i;
    }
}

ll monomial () {
    ll ans = 1;
    for (ll i = 2; i < 50; i++) {
        while (res[i]--) {
            if (ans > 1000000000000000000) return ans; 
            ans *= i;
        }
    }    
    return ans;    
}

int main () {
    ll k;
    crivo ();
    while (scanf ("%d %lld", &n, &k) && (n != 0 || k != 0)) { 
        int tam = 0;
        for (int i = 0; i < n; i++) { 
            scanf ("%lld", &v[i]);
            tam += v[i];
        }
        for (int i = 0; i < tam; i++) {
            for (int c = 0; c < n; c++) {
                if (!v[c]) 
                    continue;
                for (int j = 0; j < 50; j++) res[j] = 0;
                fatora (tam-1-i, 1);
                for (int j = 0; j < n; j++) {
                    if (j == c) fatora (v[j]-1, 0);
                    else fatora (v[j], 0);
                }
                ll val = monomial ();
                //printf ("c %d val %lld k %lld\n", c, val, k);
                if (val > k) {
                    printf ("%c", c+'a');
                    v[c]--;
                    break;
                } else 
                    k -= val;
            }
        }
        printf ("\n");
    }
}
