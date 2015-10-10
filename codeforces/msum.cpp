#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000010
#define pb push_back

using namespace std;

int n, m, sum, a;
int me[1005][1005][2];
int seq[MAX];

int pd (int i, int soma, int flag) {
    if (soma == 0 && flag) 
        return 1;
    if (i == n) 
        return 0;
    if (me[i][soma][flag] != -1) 
        return me[i][soma][flag];

    return me[i][soma][flag] = pd (i + 1, (soma + seq[i]) % m, 1) + pd (i + 1, soma, flag);
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++) 
            for (int l = 0; l <= 1; l++)
                me[i][j][l] = -1;

    for (int i = 0; i < n; i++) {
        scanf ("%d", &seq[i]);
        sum = (sum + seq[i]) % m;
    }
    if (n > m) printf ("YES\n");
    else { 
        if (pd (0, 0, 0)) {
            printf ("YES\n");
        }
        else printf ("NO\n");
    }
}
