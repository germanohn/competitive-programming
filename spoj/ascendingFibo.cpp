#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int resto = 100000;
const int lim = 1000005;
const int MAX = 1100005;

int v[lim], ans[lim], pos[lim];
int me[MAX];

int dp (int i) {
    if (i == 1) return me[i] = 0;
    if (i == 2) return me[i] = 1;
    if (me[i] != -1) return me[i];
    return me[i] = (dp (i-1) + dp (i-2)) % resto;
}

int main () {
    int t, cont = 1, a, b;
    scanf ("%d", &t);
    memset (me, -1, sizeof me);
    while (t--) {
        printf ("Case %d: ", cont++);
        scanf ("%d %d", &a, &b);
        for (int i = 0; i < lim; i++)
            pos[i] = 0;
        //calculo todos os fib de a ate a+b e coloco em um vetor
        for (int i = a; i <= a+b; i++) {
            v[i-a] = dp (i);
            pos[v[i-a]]++;
        }
        //faço ate b porque vai ate b+a - a
        for (int j = 1; j < lim; j++) 
            pos[j] += pos[j-1];
        for (int i = 0; i <= b; i++) {
            ans[pos[v[i]]] = v[i];
            pos[v[i]]--;
        }
        for (int i = 1; i <= b+1 && i <= 100; i++) {
            if (i < b+1 && i < 100) printf ("%d ", ans[i]);
            else printf ("%d\n", ans[i]); 
        }
    }
}

