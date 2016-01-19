#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, k;

int main () {
    cin >> l >> r >> k;
    ll num = 1;
    bool f = true;
    while (num <= r) {
        if (num >= l && num <= r) cout << num << " ", f = false;
        if (num > r/k) break;
        num *= k;
    }
    if (f) cout << "-1";
    cout << '\n';
}
