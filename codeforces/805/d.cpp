#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

char s[N];

int main () {
    scanf(" %s", s);
    int len = strlen(s);

    ll ans = 0;
    ll cont_b = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == 'a') {
            if (cont_b != 0) {
                ans = (ans + cont_b) % MOD;
                cont_b = (2 * (cont_b)) % MOD;
            }
        } else {
            cont_b = (cont_b + 1) % MOD;
        }
    }

    printf("%lld\n", ans % MOD);
}

