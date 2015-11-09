#include <bits/stdc++.h>
#define MAX 2690639
using namespace std;

const int N = 86100000;


unsigned int p[2690639], k;
int pri[N], n;

void crivo () {
    for (unsigned int i = 2; i*i < N; i++) {
        /* pegando o resto: */
        if (!(p[i>>5] & (1 << (i & ((1 << 6)-1))))) {
            for (unsigned int j = i*i; j < N; j += i) {
                p[j>>5] |= (1 << (j & ((1 << 6)-1)));
            }
        }
    }
    for (unsigned int i = 2; i < N; i++) {
        if (!(p[i>>5] & (1 << (i & ((1 << 6)-1))))) 
            pri[k++] = i;
        if (k > 5000000) break;
    }
}

int main () {
    crivo ();
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        printf ("%d\n", pri[n-1]);  
    }
}
