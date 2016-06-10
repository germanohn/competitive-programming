#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, a, b, c, d;
    scanf ("%d %d %d %d %d", &n, &a, &b, &c, &d);
    // pra cada x1 tem n possibilidades
    int s2, s3, s4;
    s2 = b-c;
    s3 = a-d;
    s4 = a+b-c-d;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((s2+i > 0 && s2+i <= n) && (s3+i > 0 && s3+i <= n) && (s4+i > 0 && s4+i <= n)) {
            ans += (ll) n;
        }
    }
    cout << ans << "\n";
}

