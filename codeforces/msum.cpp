#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 1000010

using namespace std;

int n, m, me[10005][1005];
long long int seq[MAX];

int pd (int i, long long int soma) {
    if (soma % m == 0 && i != 0) return 1;
    soma %= m;
    if (i == n) return 0;
    if (me[i][soma] != -1) return me[i][soma];
        return me[i][soma] = pd (i + 1, (soma + seq[i])) + pd (i + 1, soma);
}

int main () {
    memset (me, -1, sizeof (me));
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> seq[i]; 
        seq[i] %= m;
    }
    if (n > m) printf ("YES\n");
    else { 
        if (seq[0] % m == 0) {
            printf ("YES\n");
            return 0;
        }
        if (pd (0, 0)) printf ("YES\n");
        else printf ("NO\n");
    }
}
