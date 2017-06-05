#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n;
ll bit[N];
vector<int> seen;
map<int, ll> val, mp; // mapa: guarda o valor final de uma posição

void update(int idx, ll val) {
    for (int i = idx; i < N; i += i & -i)
        bit[i] += val;
}

ll query(int idx) {
    ll ans = 0;
    for (int i = idx; i > 0; i -= i & -i)
        ans += bit[i];
    return ans;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        if (val[a] == 0) val[a] = a;
        if (val[b] == 0) val[b] = b;
        swap(val[a], val[b]);
        seen.pb(a); seen.pb(b);
    }

    sort(seen.begin(), seen.end());
    auto it = unique(seen.begin(), seen.end());
    seen.resize(it - seen.begin());

    ll ans = 0;
    for (int i = 0; i < seen.size(); i++) {
        int cur = seen[i];
        if (val[cur] != cur) {
            ll a = upper_bound(seen.begin(), seen.end(), val[cur]) - seen.begin() - 1;
            ll b = upper_bound(seen.begin(), seen.end(), cur) - seen.begin() - 1; 
            ans += (abs(val[cur] - cur) - abs(a - b)); 
        }
    }

    // mapear os valores "vistos" para o intervalo seen.size()
    int k = 1;
    for (int i = 0; i < seen.size(); i++) 
        mp[seen[i]] = k++;

    for (int i = 0; i < seen.size(); i++) {
        int cur = val[seen[i]];
        ans += ((mp[cur] - 1ll) - query(mp[cur]));
        update(mp[cur], 1);
    }

    printf("%lld\n", ans);
}

