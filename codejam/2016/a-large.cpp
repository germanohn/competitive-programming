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
ll n;
set<int> vis;

void digit (int a) {
    int dig;
    // printf ("a %d\n", a);
    while (a > 0) {
        dig = a%10;
        vis.insert (dig);
        a /= 10;
    }
}

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        debug("Running test %d\n", t);
        int q = 0;
        scanf ("%lld", &n);
        vis.clear ();
        int x = n%10, ans = 0;
        if (n == 0) {
            printf ("INSOMNIA\n");
            continue;
        }
        if (x % 2 == 0 || x == 5) {
            int i = 0;
            while (vis.size () != 10) {
                q++;
                i++;
                digit (n*i);
            }
            ans = n*i;
        } else if (x != 5) {
            for (int i = 1; i <= 10; i++) {
                q++;
                digit (n*i);
                if (vis.size () == 10) { 
                    ans = n*i;
                    break;
                }
            }    
        }
        printf ("Case #%d: %d q %d\n", cont++, ans, q);
    }
}

