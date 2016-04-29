#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;
const int inf = 1123456789;

int n, v[MAX];
ll ans, l, r;

int main () {
    scanf ("%d", &n);
    l = r = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        l += v[i];
    }
    sort (v, v+n);
    ans = inf;
    for (int i = n-1; i >= 0; i--) {
        r += v[i];
        l -= v[i];
        if (l > r) {
            ans = min (ans, l-r+1);
        } else {
            ans = min (ans, r-l+1);
        }   
    }
    cout << ans << endl;
}

