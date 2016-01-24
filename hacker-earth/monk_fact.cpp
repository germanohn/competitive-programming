#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, a;

int main () {
    scanf ("%d", &n);
    int soma = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        soma += a;
    }
    if (soma == 2*(n-1))
        printf ("Yes\n");
    else printf ("No\n");
}
