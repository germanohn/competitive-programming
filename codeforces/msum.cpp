#include <cstdio>
#include <cstring>
#define MAX 1000010

using namespace std;

int n, m, seq[MAX], me[1000][1000], tot;

int pd (int i, int soma) {
    if (i > j) return 0;
    if (soma % m == 0) return 1;
    if (me[i][soma] != -1) return me[i][soma];
    int sum = (soma + seq[i]) % m;
    printf ("i %d sum %d soma %d\n", i, sum, soma);
    return me[i][soma] = pd (i, sum) + pd (i + 1, soma);
}

int main () {
    memset (me, -1, sizeof (me));
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &seq[i]);
        tot += seq[i];
    }
    if (pd (0, seq[0])) printf ("YES\n");
    else printf ("NO\n");
}
