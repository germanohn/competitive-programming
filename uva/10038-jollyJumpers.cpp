#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 100000007;
inline ll mod (ll x) { return x % modn; }

bool v[3005];
int a[3005], n;

int main () {
    while (scanf ("%d", &n) != EOF) {
        bool ans = true;
        for (int i = 0; i < n; i++) 
            v[i] = false;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &a[i]);
        }
        for (int i = 1; i < n; i++) {
            int dif = abs (a[i]-a[i-1]); 
            v[dif] = true;
        }
        int i;
        for (i = 1; i < n; i++) {
            if (!v[i]) {
                printf ("Not jolly\n");
                break; 
            }
        }
        if (i == n) printf ("Jolly\n");
    }
}

