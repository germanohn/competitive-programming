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
bool f, ok;
map<ll, pii> t;

ll dis (ll a, ll b, ll c, ll x, ll y, ll z) {
    return (a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z);
}

bool verify () {
    int k = 1, cont = 0, acc = 0;
    for (int i = 0; i < 8; i++) {
        cont = 0;
        t.clear ();
        for (int j = 0; j < 8; j++) {
            if (j != i) {
                ll val = dis (cube[i][0], cube[i][1], cube[i][2],
                              cube[j][0], cube[j][1], cube[j][2]);                        
                if (val == 0) return false;
                if (t[val] == pii (0, 0)) 
                    t[val] = pii (k++, 1), cont++;
                else {
                    t[val].ss++;
                }
            }
        }
        if (cont == 3) acc++;
    }   

    if (acc == 8) {
        int tres = 0, um = 0, pos = 0;
        bool f = true;
        for (map<ll, pii>::iterator it = t.begin (); it != t.end (); it++) {
            pos++;
            if (it->ss.ss == 3)
                tres++;
            else if (it->ss.ss == 1) {
                um++; 
                if (pos != 3) f = false;
            }
        }

        if (!f || tres != 2 || um != 1) 
            return false;
        return true;
    }
    return false;
}   

bool solve (int i) {
    if (i == 8) {
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
    for (int j = 0; !ans && j < 3; j++) {
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

    ok = false;

    if (!solve (0)) 
        printf ("NO\n");
}

