#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int n;
int v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    sort (v, v + n);
    int quant = (n-1)/2;
    int ini = 0, fim = n-1;
    while (quant--) {
        if (v[fim-1]-v[ini] <= v[fim]-v[ini+1])
            fim--;
        else 
            ini++;
    }
    printf ("%d\n", v[fim]-v[ini]);
}
