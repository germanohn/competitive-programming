#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int v[N];
vector<int> s;

ll solve(int ini) {
    bool f = true;
    for (int i = ini; i < n - 1; i++, f = !f) {
        int a = abs(v[i + 1] - v[i]);
        if (f) 
            s.pb(a);
        else
            s.pb(-a);
    }

    ll ans = 0, aux = 0;
    for (int i = 0; i < s.size(); i++) {
        aux += ll(s[i]);
        if (aux > ans) 
            ans = aux;
        else if (aux < 0) 
            aux = 0;
    }

    return ans;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    ll ans = solve(0);
    s.clear();
    ans = max(ans, solve(1));
    printf("%lld\n", ans);
}

