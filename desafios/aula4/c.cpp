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

const int MOD = 1000000007;

int mod (ll a) { return (a+MOD) % MOD; }
 
ll fexp (ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return mod (b);
    if (e % 2 == 0) return mod (fexp (mod (b*b), e/2));
    return mod ((b*fexp (mod (b*b), e/2)));
}

int inv (ll a) { return fexp (a, MOD-2); }

int main () {
    ll a, b, x, ans;
    ll n;
    scanf ("%lld %lld %lld %lld", &a, &b, &n, &x);
    if (a != 1) {
        ll a_n = fexp (a, n), rev = inv (a-1);
        //printf ("a %lld n %lld a_n %lld rev %lld\n", a, n, a_n, rev);
        int p1 = mod (a_n * x);
        int p2 = mod (b * mod ((mod (a_n * rev) - rev))); 
        //printf ("p1 %d p2 %d\n", p1, p2);
        ans = mod (p1 + p2);
    } else {
        ans = mod (x + mod (b*mod (n)));
    }
    printf ("%lld\n", ans);
}

