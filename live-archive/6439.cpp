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

const ll MOD = 1e9 + 7;
const int MAX = 50005;

int t, ans;
char s[MAX];
ll p = 263;
ll h[MAX];
ll x[MAX];

inline ll mod (ll x) {
    return (x % MOD);
}

ll calc (int i, int j) {
    return mod (h[j+1] - mod (h[i]*x[j-i+1]) + MOD);
}

int main () {
    scanf ("%d", &t);
    int teste = 1;
    while (t--) {
        ans = 0;
        scanf (" %s", s); 
        h[0] = 0;
        x[0] = 1;
        int n = strlen (s);
        for (int i = 1; i <= n; i++) {
            h[i] = (h[i-1]*p + s[i-1]) % MOD;
            x[i] = (x[i-1]*p) % MOD;
        }
        int l, r; // l é o exclusive
        l = 0, r = n-1;
        for (int i = 0; i < (n+1)/2; i++) {
            ll a = calc (l, i);
            ll b = calc (n-i-1, r);
            if (a == b) {
                if (l != r)
                    ans += 2;
                else 
                    ans++;
                l = i+1;
                r = n-i-2;
            }
        }
        //printf ("l %d r %d\n", l, r);
        if (r > l)
            ans++;
        printf ("Case #%d: %d\n", teste++, ans);
    }    
}

