#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll memo[40][40][2];
int a, b, n;

ll dp (int i, int sum, bool pre) {
    if (i == -1) return sum;
    ll m = memo[i][sum][pre];
    if (m != -1) return m;
    ll r = 0;
    for (int d = 0; d <= 1; d++) {
        //!!(n&(1<<i)) sera o digito do numero n na posicao i
        if (pre && d > !!(n & (1<<i))) break;
        r += dp (i-1, sum + d, pre && d == !!(n & (1<<i)));
    }
    return memo[i][sum][pre] = r;
}

int main () {
    int cont = 1;
    while (scanf ("%d %d", &a, &b) &&  b != 0) {
        ll mini = 0, maxi = 0;
        if (a != 0) {
            memset (memo, -1, sizeof (memo));
            n = a-1;
            // como o limite de a e b é 2*10e9, pra representar esse numero é preciso 31 posicoes 
            // na representacao binaria e como terei i ate 0 entao coloco 30 como primeiro estado
            mini = dp (30, 0, true);
        }
        n = b;
        memset (memo, -1, sizeof (memo));
        maxi = dp (30, 0, true);
        printf ("Case %d: %lld\n", cont++, maxi - mini);
    }
}
