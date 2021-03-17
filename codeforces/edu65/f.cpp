#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 5 * 1e5 + 5;
const ll MOD = 1e9 + 7;

ll n;
ll a[N], b[N], bit[N][2];
map<int, ll> pos;

ll mod(ll x) {
    return (x + MOD) % MOD;
}

void update(int idx, ll val, char c) {
    bool k = c == 'l' ? 0 : 1;
    for (int i = idx; i <= n; i += i & -i) {
        bit[i][k] = mod(bit[i][k] + val);
    }
}

ll query(int idx, char c) {
    bool k = c == 'l' ? 0 : 1;
    ll sum = 0;
    for (int i = idx; i > 0; i -= i & -i) 
        sum = mod(sum + bit[i][k]);
    return sum;
}

int main() {
    scanf(" %lld", &n);

    for (int i = 1; i <= n; i++) {
        scanf(" %lld", &a[i]);
        b[i] = a[i];
        pos[a[i]] = i;
    }

    sort(b + 1, b + 1 + n);

    ll ans = 0;
    // calcula contribuição de cada 
    for (int i = 1; i <= n; i++) {
        ll k = pos[b[i]];

        // contribuição de a[k] em cada sequência que está, supondo ele na primeira posição.
        ans = mod(ans + mod(a[k] * mod(k * (n - k + 1))));

        // contribuição de todos os menores que a[k] que vem antes dele com o a[k]
        ans = mod(ans + mod(a[k] * mod(query(k, 'l') * (n - k + 1))));

        // contribuição de todos os menores que a[k] que vem depois dele com o a[k]
        ans = mod(ans + mod(a[k] * mod(k * mod(query(n, 'r') - query(k, 'r')))));

        update(k, k, 'l');
        update(k, n - k + 1, 'r');
    }

    printf("%lld\n", ans);
}

