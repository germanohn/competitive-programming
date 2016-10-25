#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, cont;
int v[2005];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    for (int i = 2; i < n; i += 3) {
        if (v[i] + k <= 5) cont++;
        else break;
    }
    
    printf("%d\n", cont);
}

