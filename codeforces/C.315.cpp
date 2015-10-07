#include <bits/stdc++.h>
#define MAX 10000005

using namespace std;

long long p, q, d, pi[MAX], rub[MAX];


void crivo () {
    for (long long i = 2; i < MAX; i++) {
        if (!pi[i]) {
            for (long long j = 2; i * j < MAX; j++) 
                pi[i * j] = 1;
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
        for (int j = 0; j < k / 2; j++) {
            if (num[j] != num[k - 1 - j])
                f = false;
        }
        if (f) {
            rub[i] = rub[i-1] + 1;
        }
        else
            rub[i] = rub[i-1];

        if (i > 1167450 && i < 1167800)
            printf ("i %d rub %lld pi %lld num %s\n", i, p * rub[i], q * pi[i], num); 
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
         
     
    
    long long lo = 1, hi = MAX - 1;
    while (lo != hi) {
        long long mid = (lo + hi + 1) / 2;
            long long m = p * rub[mid];
        if (q * pi[mid] <= m)
            lo = mid;
        else
            hi = mid - 1; 
    } 
    cout << lo << endl;
}
