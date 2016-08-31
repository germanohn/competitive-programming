#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const ll inf = 1e14;
const int MAX = 105;

int n, m, k;
int color[MAX];
ll p[MAX][MAX];
ll me[MAX][MAX][MAX];


ll dp (int i, int ult, int size) {
    if (i == n) {
        if (size == k) return 0;
        else return inf;
    }
    if (me[i][ult][size] != -1) return me[i][ult][size];
    if (color[i] != 0) {
        if (color[i] != ult) return me[i][ult][size] = dp (i+1, color[i], size+1);
        else return me[i][ult][size] = dp (i+1, color[i], size);
    }

    ll ans = inf;
    for (int j = 1; j <= m; j++) {
        if (j != ult) ans = min (ans, p[i][j] + dp (i+1, j, size+1));
        else ans = min (ans, p[i][j] + dp (i+1, j, size));
    }
    
    return me[i][ult][size] = ans;
}

int main () {
    memset (me, -1, sizeof me);
    scanf (" %d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf (" %d", &color[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf ("%lld", &p[i][j]);
        }
    }

    ll ans = dp (0, 101, 0);
    if (ans < inf) printf ("%lld\n", ans);
    else printf ("-1\n");
}

