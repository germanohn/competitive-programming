#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf(" %d", &n);

    ll ant = 1, at = 10, qtd_num = 9, casa = 1;
    ll ans = 0;
    while (n >= at) {
        ans += (qtd_num * casa);
        ant *= 10, at *= 10, qtd_num *= 10;
        casa++;
    }

    ans += ((n - ant + 1) * casa);
    printf("%lld\n", ans);
}
