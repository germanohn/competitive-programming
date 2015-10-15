#include <cstdio>

using namespace std;

int n, a, b, soma[10005], v[10005], freq[10005];

int main () {
    scanf ("%d", &n);
    soma[0] = 0;
    int k = -1;
    for (int i = 0; i < n; i++) 
        freq[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &v[i]);
        soma[i] = (soma[i-1] + v[i]) % n;
        if (soma[i] == 0) 
            k = i;
        freq[soma[i]]++;
    }
    if (k != -1) {
        printf ("%d\n", k);
        for (int i = 1; i <= k; i++) 
            printf ("%d\n", v[i]);
        return 0;
    }
    int resto = -1;
    for (int i = 0; i < n; i++) {
        if (freq[i] > 1) {
           resto = i;
           break;
        }
    }
    if (resto == -1) 
        printf ("0\n");
    else {
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
        printf ("%d\n", b-a);
        for (int i = a + 1; i <= b; i++) 
            printf ("%d\n", v[i]);
    }
}
