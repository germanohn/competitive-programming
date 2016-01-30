#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, v[105];
ll m[105];

ll dp (int ind) {
    if (ind == n) return 1;
    if (m[ind] != -1) return m[ind];
    bool ok = false;
    ll tmp = 0;
    for (int i = ind; i <= n; i++) {
        if (!ok) {
            if (v[i] == 1) {
                ok = 1;
                tmp += dp (i+1);
            }
        } else {
            if (v[i] != 1)
                tmp += dp (i+1);
            else break;
        }
    }
    return m[ind] = tmp;
}

int main () {
    memset (m, -1, sizeof m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << dp (0) << endl;
}
