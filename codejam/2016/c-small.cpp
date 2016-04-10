#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) //fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MAX = 100000000;

int t, n, j;
ll p[MAX], pri[MAX], divis[55];

void sieve () {

    for (ll i = 2; i < MAX; i++) {
        if (!p[i]) 
            for (ll k = i*i; k < MAX; k += i) 
                p[k] = true;
    }
    debug("sieve \n");
    int k = 0;
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) 
            pri[k++] = i;
    }
}

ll prime (ll base, char aux[]) {
    ll num = 0, pot = 1; 
    debug("prime\n");
    for (int i = n-1; i >= 0; i--) {
        ll dig = aux[i]-'0';   
        num += dig*pot;
        pot *= base;        
    }   
    //printf ("base %lld num %lld\n", base, num);
    for (int i = 0; pri[i] <= sqrt (num); i++) {
        debug("pri[i] %lld\n", pri[i]);
        if (num % pri[i] == 0) {
            return pri[i];    
        }
    } 
    debug("depois de verificar se é primo\n");
    return 0;
} 

void construct (char* s) {
    bool carry = true;
    for (int i = n-2; carry && i >= 1; i--) {
        if (s[i] == '1') {
            s[i] = '0';
            carry = true;
        } else {
            s[i] = '1'; 
            carry = false;
        }
    }
}

int main () {
    int test = 1, cont;
    scanf ("%d", &t);
    sieve ();
    while (t--) {
        scanf ("%d %d", &n, &j);
        char s[20];
        s[0] = '1';
        for (int i = 1; i < n-1; i++)
            s[i] = '0';
        s[n-1] = '1';
        s[n] = 0;
        //debug("%s\n", s);
        cont = 0;
        printf ("Case #%d:\n", test++);
        while (cont < j) {
            bool f = true;
 //           printf ("%s\n", s);
            for (int base = 2; f && base <= 10; base++) {
                divis[base-2] = prime (base, s);
                if (divis[base-2] == 0) 
                    f = false;
            }
            debug("bah\n"); 
           // printf ("%s\n", s);
            if (f) {
                cont++;    
                printf ("%s ", s);
                for (int i = 0; i < 9; i++) 
                   printf ("%lld ", divis[i]); 
                printf ("\n");
            }
            construct (s);
        }
    }
}

