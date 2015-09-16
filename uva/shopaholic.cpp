#include <cstdio>
#include <algorithm>
#define MAX 200010

using namespace std;

int t, n, p[MAX];

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
            scanf ("%d", &p[i]);
        sort (p, p + n);
        int soma = 0;
        for (int i = n - 3; i >= 0; i = i - 3) 
            soma += p[i];
        printf ("%d\n", soma);
    }
}
    
