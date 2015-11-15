/* invariante do problema: quando ajeito um Ai, todos os
// Ai da frente ficam igual, logo o quanto precisa ajeitar
// para um dado Ai, é a diferenca entre Bi e Bi-1, pois quando 
// chegar em Ai, esse sera igual ao Bi-1.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll ans, v[200005];

int main () {
    scanf ("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf ("%I64d", &v[i]);
    }
    ans = abs (v[0]);
    for (int i = 1; i < t; i++) {
        ans += abs (v[i] - v[i-1]);
    }
    printf ("%I64d\n", ans);
}
