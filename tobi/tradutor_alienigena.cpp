#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

char c[105], n[MAX];
long long int memo[MAX], tam;

bool ordena (int i, int j) {
    if (j - i + 1 < tam) return true;
    else if (j - i + 1 > tam) return false;

    while (i <= j && n[i] == c[i]) 
        i++;
    if (i > j) return true;
    if (n[i] <= c[i]) return true;
    return false;
    
}

long long int pd (int i) {
    if (n[i] == '\0') return 1;
    long long int &m = memo[i], tot = 0;
    if (m != -1) return m;
    for (int j = i; j < i + 100 && n[j] != '\0'; j++) {     
        printf ("oi\n"); 
        printf ("n[%d] %c\n", j, n[j]);    
        if (n[i] != '0' && ordena (i, j)) 
            tot += pd (j + 1);
        printf ("tot %d\n", tot);
    }
    return m = tot;
}

int main () {
    scanf ("%s %s", c, n);
    tam = strlen (c);
    printf ("tam %d\n", tam);
    for (int i = 0; n[i] != '\0'; i++) 
        memo[i] = -1;
    printf ("%lld\n", pd (0) % 1000000007);   
}
