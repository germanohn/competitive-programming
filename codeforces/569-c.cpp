#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 10000007;
const double eps = 1e-8;

int p, q;
int prime[MAXN], accPrime[MAXN], accPalin[MAXN];

void sieve () {
    prime[1] = false;
    for (int i = 2; i*i < MAXN; i++) 
        if (!prime[i]) 
            for (int j = i*i; j < MAXN; j += i)
                prime[j] = true;
}

bool isPalin (int n) {
    int num = n, rev = 0, dig;
    while (num > 0) {
        dig = num % 10;
        rev = rev * 10 + dig;
        num /= 10;
    }
    if (n == rev)
        return true;
    else 
        return false;
}

int main () {
    scanf ("%d %d", &p, &q);
    sieve ();

    accPrime[1] = 0;
    accPalin[1] = 1;

    for (int i = 2; i < MAXN; i++) {
        accPrime[i] = accPrime[i-1];
        accPalin[i] = accPalin[i-1];
        if (!prime[i]) 
            accPrime[i]++;
        if (isPalin (i)) {
            accPalin[i]++;
        }
    }
    
    int ans = 0;
    for (int i = 1; i < MAXN; i++) {
        if ((ll) accPrime[i]*q <= (ll) p*accPalin[i])
            ans = i;
    }

    if (ans == 0)
        printf ("Palindromic tree is better than splay tree\n");
    else 
        printf ("%d\n", ans);
}


