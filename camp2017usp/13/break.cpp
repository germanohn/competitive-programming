#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (c == a*b) {
            cout << 0 << endl;
            continue;
        }
        if (c % a == 0 || c % b == 0) {
            cout << 1 << endl;
            continue;
        }

        bool ok = false;
        ll mini = min(a, b);
        for (ll i = 1; i <= mini; i++) {
            if (c % i == 0 && c/i <= max(a, b)) {
                ok = true;
                break;
            }
            if ((a*b - c) % i == 0 && (a*b - c)/i <= max(a, b)) {
                ok = true;
                break;
            }
        }
        if (ok) cout << 2 << endl;
        else cout << 3 << endl;
    }
}

