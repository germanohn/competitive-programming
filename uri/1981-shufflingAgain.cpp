#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 100000007;
ll v[50], fat[10005];
char s[10005];

ll fexp (ll base, ll exp) {
    if (exp == 0) return 1; 
    if (exp == 1) return base;
    if (exp % 2 == 0) return fexp ((base*base) % MOD, exp/2) % MOD;
    return (base*fexp ((base*base) % MOD, exp/2)) % MOD;
}

void fatorial () {
    fat[0] = 1;
    for (ll i = 1; i <= 10000; i++) 
        fat[i] = (fat[i-1]*i) % MOD;
}

int main () {
    fatorial ();
    while (scanf (" %s", s) && s[0] != '0') {
        for (int i = 0; i < 50; i++) 
            v[i] = 0;
        for (int i = 0; s[i] != '\0'; i++) 
            v[s[i]-'a']++;
        ll num = 1, den = 1, ans, tam = strlen (s);
        for (int i = 0; i < 50; i++) 
            den = (den * fat[v[i]]) % MOD;        
        num = fat[tam];
        ans = (num*fexp (den, MOD-2))%MOD;
        printf ("%lld\n", ans);
    }
}






