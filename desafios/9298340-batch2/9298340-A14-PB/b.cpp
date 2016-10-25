#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int cube[10][5];
vector<ll> side;

ll dis (ll a, ll b, ll c, ll x, ll y, ll z) {
    return (a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z);
}

bool verify () {
    for (int i = 0; i < 8; i++) {
        side.clear ();
        for (int j = 0; j < 8; j++) {
            if (i == j) continue;
            side.pb (dis (cube[i][0], cube[i][1], cube[i][2],
                          cube[j][0], cube[j][1], cube[j][2]));
        }
        sort (side.begin (), side.end ());

        if (side[0] != side[1] || side[0] != side[2] || 
            side[3] != side[4] || side[3] != side[5] ||
            side[3] != 2 * side[0] || side[6] != 3 * side[0] ||
            side[0] == side[3] || side[0] == side[6]) 
            return false;
    }

    return true;
}   

bool solve (int i) {
    if (i == 8) {
        /*printf ("\n");
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                printf ("%d ", cube[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");*/

        if (verify ()) {
            printf ("YES\n");
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 3; j++) {
                    printf ("%d ", cube[i][j]);
                }
                printf ("\n");
            }
            return true;        
        }
        return false;
    }
    bool ans = false;
    for (int j = 0; !ans && j < 6; j++) {
        if (j != 0) 
            next_permutation (cube[i], cube[i]+3);
        ans = solve (i+1);
    }

    return ans;
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            scanf (" %d", &cube[i][j]);
        }
    }  

    if (!solve (0)) 
        printf ("NO\n");
}

