//entao eu quero atender um numero n de pessoas com um tamanho maximo de pao
//igual ao 3635-pie do live archive
#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

int n, k;
int p[MAX];

int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < k; i++) 
        scanf ("%d", &p[i]);
    sort (p, p + k);
    int lo = 1, hi = p[k-1];
    while (lo != hi) {
        int tot = 0;
        int mid = (lo + hi + 1) / 2;
        for (int i = 0; i < k; i++) 
            tot += p[i]/mid;
        
            printf ("tot %d lo %d hi %d mid %d\n", tot, lo, hi, mid);
        if (tot >= n) lo = mid;
        else hi = mid - 1;
      
    }
    printf ("%d\n", hi);
}
