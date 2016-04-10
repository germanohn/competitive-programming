#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;
ll n, ans;
set<int> vis;

void digit (ll a) {
    int dig;
    while (a > 0) {
        dig = a%10;
        vis.insert (dig);
        a /= 10;
    }
}

int main () {
    scanf ("%d", &t);
    int cont = 1, q, x;
    ll i;
    while (t--) {
        debug("Running test %d\n", t);
        scanf ("%lld", &n);
        vis.clear ();
        x = n%10, q = 0;
        if (n == 0) {
            printf ("Case #%d: INSOMNIA\n", cont++);
            continue;
        }
        if (x % 2 == 0 || x == 5) {
            i = 0;
            while (vis.size () != 10) {
                q++;
                i++;
                digit (n*i);
            }
            ans = n*i;
        } else if (x != 5) {
            for (i = 1; i <= 10; i++) {
                q++;
                digit (n*i);
                if (vis.size () == 10) { 
                    ans = n*i;
                    break;
                }
            }    
        }
        printf ("Case #%d: %lld\n", cont++, ans);
    }
}

