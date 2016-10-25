#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 205;

int n;
int v[MAX];
int me[MAX][MAX][MAX];

int dp (int i, int ant_b, int ant_w) {
    if (i == n+2) return 0;

    if (me[i][ant_b][ant_w] != -1) return me[i][ant_b][ant_w];

    int ans;
    if (v[ant_b] < v[i]) {
        if (v[ant_w] > v[i]) {
            ans = min (dp (i+1, i, ant_w), 
                       min (dp (i+1, ant_b, i), 1 + dp (i+1, ant_b, ant_w)));
        } else {
            ans = min (dp (i+1, i, ant_w), 1 + dp (i+1, ant_b, ant_w));
        }
    } else {
        if (v[ant_w] > v[i]) {
            ans = min (dp (i+1, ant_b, i), 1 + dp (i+1, ant_b, ant_w));
        } else {
            ans = 1 + dp (i+1, ant_b, ant_w);
        }
    }

    return me[i][ant_b][ant_w] = ans;
}

int main() {
    while (scanf (" %d", &n)) {
        if (n == -1) break;
        memset (me, -1, sizeof me);
            
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i+2]);
        }

        v[0] = 0;
        v[1] = 1e7;
        printf ("%d\n", dp (2, 0, 1));
    }
}

