#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int t, l, r, k;
char s[MAX], aux[MAX];

int main () {
    scanf ("%s %d", s, &t);
    while (t--) {
        scanf ("%d %d %d", &l, &r, &k);
        l--, r--;
        for (int i = l; i <= r; i++) 
            aux[((i-l+k)%(r-l+1)) +l] = s[i];
         
        for (int i = l; i <= r; i++) 
            s[i] = aux[i];
        
    }
    printf ("%s\n", s);
}

