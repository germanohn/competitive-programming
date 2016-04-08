#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

int dif[100005];

int main () {
    int t, cont = 1;
    scanf ("%d", &t);
    while (t--) {
        int n, a = 0, b, ma = 0;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &b);
            dif[i] = b-a;
            if (b-a > ma) ma = b-a;
            a = b;
        }
        int i, aux = ma;
        for (i = 0; i < n; i++) {
            if (dif[i] == aux) {
                aux--;  
            } else if (dif[i] > aux) {
                aux = -1;
                break;  
            }
        }
        printf ("Case %d: ", cont++);
        if ((aux <= -1 && i != n) || aux < -1) printf ("%d\n", ma+1);
        else printf ("%d\n", ma);
    }
}

