#include <bits/stdc++.h>

using namespace std;

int n, c, soma[100005], a, b, freq[100005], resto;

int main () {
    while (scanf ("%d %d", &c, &n) && c != 0) {
        memset (freq, 0, sizeof (freq));
        soma[0] = 0;
        int k = -1;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &a);
            soma[i] = (soma[i-1] + a) % c;
            if (soma[i] == 0) k = i;
            freq[soma[i]]++;
        }
        if (k != -1) {
            for (int i = 1; i <= k; i++)
                printf ("%d ", i);
            printf ("\n");
            continue;
        }
        int resto;
        for (int i = 0; i < c; i++) {
            if (freq[i] > 1) {
                resto = i;
                break;
            }
        }
        a = -1, b = -1;
        for (int i = 1; i <= n; i++) {
            if (soma[i] == resto) {
                if (a == -1) 
                   a = i;
                else if (b == -1)
                   b = i; 
                else
                   break;
            }
        }
        for (int i = a+1; i <= b; i++) 
            printf ("%d ", i); 
        printf ("\n");
    }
}
