#include <bits/stdc++.h>
#define MAX 10000005
using namespace std;
typedef long long ll;

long long p, q, d, pi[MAX], rub[MAX];


void crivo () {
    for (long long i = 2; i < MAX; i++) {
        if (!pi[i]) {
            for (long long j = i*i; j < MAX; j += i) 
                pi[j] = 1;
        }
    }
}

void palindromo () {
    rub[0] = 0;
    for (int i = 1; i < MAX; i++) {
        char num[10];
        long long k = 0, aux = i;
        while (aux > 0) {
            num[k++] = (aux%10) + '0';
            aux /= 10;
        }
        num[k] = '\0';
        bool f = true;
        if (num[0] != '0') {
            for (int j = 0; j < k / 2; j++) {
                if (num[j] != num[k - 1 - j])
                    f = false;
            }
        } else {
            f = false;
        }
        if (f) 
            rub[i] = rub[i-1] + 1;
        else
            rub[i] = rub[i-1];
    }
}

long long mdc (long long a, long long b) {
    if (b == 0) return a;
    return mdc (b, a % b);
}

int main () {
    for (int i = 0; i < MAX; i++) 
        pi[i] = 0;
    
    crivo ();
    
    for (int i = 2; i < MAX; i++) {
       if (pi[i] == 0)
          pi[i] = pi[i-1] + 1;
       else
          pi[i] = pi[i-1];
    }
    
    cin >> p >> q;     
    d = mdc (p, q);
    p /= d, q /= d;
    palindromo ();
         
    int ans = 0;
    for (int i = 1; i < MAX; i++) {
        if ((ll) pi[i]*p <= (ll) q*rub[i])
            ans = i;
    }    
   


    if (ans == 0) 
        printf ("Palindromic tree is better than splay tree\n");
    else 
        printf ("%d\n", ans);
}
