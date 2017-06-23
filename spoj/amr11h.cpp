#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int t;
int v[N], ff_min[N], ff_max[N];
ll n;
ll pot[N];

ll mod(ll x) {
    return (x + MOD) % MOD;
}

int main () {
    pot[0] = 1;
    for (int i = 1; i < N; i++) 
        pot[i] = mod(pot[i - 1] * 2ll);

    scanf(" %d", &t);
    while (t--) {
        scanf(" %lld", &n);
        
        int _max, _min;
        _max = -1, _min = MOD;
        for (int i = 0; i < n; i++) { 
            scanf(" %d", &v[i]);
            _max = max(_max, v[i]);
            _min = min(_min, v[i]);
        }

        int q_max = 0, q_min = 0;
        ff_max[n] = ff_min[n] = n;
        for (int i = n - 1; i >= 0; i--) {
            ff_min[i] = ff_min[i + 1];
            ff_max[i] = ff_max[i + 1];
            if (v[i] == _min)
                ff_min[i] = i, q_min++;
            if (v[i] == _max)
                ff_max[i] = i, q_max++;
        }

        if (_min == _max) {
            printf("%lld %lld\n", mod((n * (n + 1)) / 2), mod(pot[n] - 1));
        } else {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] == _min) {
                    ans = mod(ans + (n - ff_max[i]));
                } else if (v[i] == _max) {
                    ans = mod(ans + (n - ff_min[i]));
                } else {
                    ans = mod(ans + (n - max(ff_max[i], ff_min[i])));
                }
            }
            printf("%d ", ans);
            ans = mod(mod(mod(pot[q_min] - 1) * mod(pot[q_max] - 1)) * pot[n - (q_min + q_max)]);
            printf("%d\n", ans);
        }
    }
}
