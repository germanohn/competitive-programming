#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll a, b, c, n, ans;

int main () {
    cin >> n >> a >> b >> c;
    if (n > b) {
        if (b - c >= a) ans = n/a;
        else if (b - c < a && b >= a) {
            ll ans = n/(b - c), aux = (n - b)/(b - c);
            aux -= (ans-1)*(b - c);
            if (aux < b && aux < a) ans--;
        }
        else if (b - c < a && b < a) 
            ans = n/(b - c);
    }
    else 
        ans =  n/a;
    cout << ans << endl;
}
