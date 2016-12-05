#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf(" %d", &n);
    ll pot = 10, qtd_num = 9, casa = 1, ans = 0;
    while (n >= pot) {
        ans += (qtd_num * casa);
        pot *= 10, qtd_num *= 10, casa++;
    }
    ans += ((n - pot/10 + 1) * casa);
    printf("%lld\n", ans);
}
