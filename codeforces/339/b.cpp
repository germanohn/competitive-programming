#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, m, ant, at;
    scanf(" %d %d", &n, &m);
    scanf(" %d", &ant);
    ll ans = ant - 1;
    for (int i = 1; i < m; i++) {
        scanf(" %d", &at);
        if (at < ant) ans += ll (n - ant + at);
        else ans += ll (at - ant);
        ant = at;
    }
    printf("%lld\n", ans);
}

