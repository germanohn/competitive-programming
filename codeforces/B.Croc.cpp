#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, k;

int main () {
    cin >> n >> k;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {  
        if (i <= k) 
            ans += n-i;
        else if (i > k && i <= n-k) 
            ans += k;
        else
            ans += n-i; 
    }
    cout << ans << endl;
}

