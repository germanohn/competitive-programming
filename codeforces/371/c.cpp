#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MAX = 1e12 + 100;

ll r;
ll need[3], price[3], has[3];
char s[105];

bool can(ll cont) {
    ll aux_r = r;
    bool ok = true;
    for (int i = 0; ok && i < 3; i++) {
        ll cost = (need[i] * cont - has[i]) * price[i];
        if (cost < 0) cost = 0;
        if (cost > aux_r) {
            ok = false;
        } else {
            aux_r -= cost;
        }
    }
    return ok;
}

int main () {
    scanf(" %s", s);
    for (int i = 0; i < 3; i++)
        scanf(" %lld", &has[i]);
    for (int i = 0; i < 3; i++) 
        scanf(" %lld", &price[i]);
    scanf(" %lld", &r);

    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'B') {
            need[0]++;
        } else if (s[i] == 'S') {
            need[1]++;
        } else {    
            need[2]++;
        }
    }

    ll lo = 0, hi = MAX;
    while (lo != hi) {
        ll mid = (lo + hi + 1) / 2;
        if (can(mid)) 
            lo = mid;
        else 
            hi = mid - 1;
    }

    printf("%lld\n", lo);
}

