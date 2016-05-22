#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 3005;

int n; 
ll v[MAX], acc[MAX], me[MAX][MAX];

int bs (ll sum) {
    int l = 0, h = n, m;
    while (l < h) {
        m = (l+h)/2;
        if (acc[m+1] >= sum)
            h = m;
        else 
            l = m+1;
    }
    return l;
}

ll dp (int i, int j) {
    if (j >= n || i >= n || i > j)
        return 0;
    if (me[i][j] != -1) return me[i][j];
    // temos que procurar no vetor o indice k tal que possua pelo menos acc[j] - acc[i-1] a mais 
    // de acc[j]. lembrando que acc esta indexado de 1, entao i-1 é i, j é j+1
    ll sum = acc[j+1] - acc[i] + acc[j+1];
    int k = bs (sum); 
    // outra maneira usando lower_bound
    //int k = lower_bound(acc, acc+n+1, acc[j+1]-acc[i]+acc[j+1]) - acc - 1;
    return me[i][j] = max (dp (i, j+1), 1 + dp (j+1, k));
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        memset (me, -1, sizeof me);
        acc[0] = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%lld", &v[i]);
            acc[i+1] = acc[i] + v[i];
        }
        acc[n+1] = 3003l*INT_MAX;
        printf ("%lld\n", dp (0, 0));
    }

}

