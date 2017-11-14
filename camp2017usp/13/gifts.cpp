#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main () {
    int n;
    cin >> n;
    ll ans = 1ll;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        v.pb(c);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        ans = (ans * (v[i] - i)) % 1000000007;
        if (v[i] < i) {
            ans = 0;
        }
    }
    cout << ans << endl;
}

