#include <bits/stdc++.h>
using namespace std;

int n, k;
int v[100005];

int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    int cont = 1, sum = 0;
    while (k > sum + cont) {
        sum += cont;
        cont++;
    }
    int ind = k-sum-1;
    printf ("%d\n", v[ind]);
}
