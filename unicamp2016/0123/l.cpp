#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;
typedef long long ll;

int v[MAX], aux[MAX];
ll cont = 0;

void intercala (ll l, ll m, ll r) {
    ll k = 0, i = l, j = m, tmp = 0;
    while (i < m && j < r) {
        if (v[i] < v[j]) aux[k++] = v[i++], tmp++;
        else {
            aux[k++] = v[j++];
            cont += m-l-tmp;
        }
    }
    while (i < m) aux[k++] = v[i++];
    while (j < r) aux[k++] = v[j++];
    for (int i = 0; i < k; i++)
        v[l+i] = aux[i];
}

void mergesort (ll l, ll r) {
    if (l != r-1) {
        ll m = (l+r)/2;
        mergesort (l, m);
        mergesort (m, r);
        intercala (l, m, r);
    }
}

int main () {
    ll n;
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    mergesort (0, n);
    printf ("%lld\n", cont);
}
