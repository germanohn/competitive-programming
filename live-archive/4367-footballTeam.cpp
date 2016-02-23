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

int n;
int ans[1005];

int main () {
    int cont = 1;
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) 
            ans[i] = 0;
        int antes = 0, depois = 0, a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf ("%d", &a);
                ans[i] -= a;
                ans[j] += a; 
                antes += a;
            }
        }
        for (int i = 0; i < n; i++) 
            if (ans[i] > 0) depois += ans[i];
        printf ("%d. %d %d\n", cont++, antes, depois);
    }
}
