#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;
const ll INF = 1e12 + 7;

ll ts, tf, t, n;  
ll v[MAX], ok[MAX];

int main () {
    scanf(" %lld %lld %lld %lld", &ts, &tf, &t, &n);
    if (n == 0) {
        printf("%lld\n", ts);
        return 0;
    }
    for (int i = 1; i <= n; i++) 
        scanf(" %lld", &v[i]);
    ok[0] = ts;
    for (int i = 1; i <= n; i++) {
        if (v[i] < ok[i - 1])
            ok[i] = ok[i - 1] + t;
        else 
            ok[i] = v[i] + t;
    }
    v[n + 1] = ok[n] + 1;
    ll ans = INF, pos;
    for (int i = 1; i <= n + 1; i++) {
        ll arrive = min(ok[i - 1], v[i] - 1);
        ll aux = (ok[i - 1] - arrive) + t;
        if (arrive + aux > tf)
            break;
        else {
            if (aux < ans) {
                ans = aux;
                pos = arrive;
            }
        }
    }
    printf("%lld\n", pos);
}
