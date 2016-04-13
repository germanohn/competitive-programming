#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 205;
const int MOD = 100000000;

int m, n, s, f, tam;
int v[MAX];
int me[MAX][MAX][MAX];
pii inter[MAX];


int dp (int i, int e1, int e2) {
    if (i == n) {
        return e2 == tam-1;
    }
    if (e1 == 0 && e2 == 0) {
        int ans = 0;
        if (inter[i].ff == 0)
            ans += dp (i+1, 0, inter[i].ss);
        ans += dp (i+1, 0, 0);
        if (ans >= MOD)
            ans %= MOD;
        return me[i][e1][e2] = ans;
    }
    if (me[i][e1][e2] != -1) return me[i][e1][e2];
    int ans;
    ans = dp (i+1, e1, e2);
    if (inter[i].ff <= e2 && inter[i].ss > e2 && inter[i].ff > e1)
        ans += dp (i+1, e2, inter[i].ss);
    if (ans >= MOD) 
        ans %= MOD;
    return me[i][e1][e2] = ans;
}

int main () {
    while (scanf ("%d %d", &m, &n) && m != 0 && n != 0) {
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &a, &b);
            v[2*i] = a;
            v[2*i+1] = b;
            inter[i].ff = a;
            inter[i].ss = -b;
        }
        v[2*n] = m;
        v[2*n+1] = 0;
        sort (v, v+2*n+2);
        tam = unique (v, v+2*n+2) - v;
        for (int i = 0; i < n; i++) 
            for (int e1 = 0; e1 < tam; e1++) 
                for (int e2 = 0; e2 < tam; e2++) 
                    me[i][e1][e2] = -1;
        for (int i = 0; i < n; i++) {
            inter[i].ff = lower_bound (v, v+tam, inter[i].ff) - v;
            inter[i].ss = -(lower_bound (v, v+tam, -inter[i].ss) - v);
        }
        sort (inter, inter+n);
        for (int i = 0; i < n; i++) 
            inter[i].ss = -inter[i].ss;
        printf ("%d\n", dp (0, 0, 0));
    }
}

