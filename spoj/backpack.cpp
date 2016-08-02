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

const int MAX = 65;

int n;
int me[MAX][33000], v[MAX][3]; // 0: volume, 1: importancia, 2: good ou attachment
vector<pii> good[MAX];

ll dp (int i, int rest) {
    if (i == n) return 0;
    if (me[i][rest] != -1) return me[i][rest];
    ll ans = dp (i+1, rest);
    if (v[i][2] == 0 && rest-v[i][0] >= 0) {
        ll aux = v[i][0]*v[i][1];
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    int q = good[i].size ();
                    ll acc = (((a == 1 && q >= 1) ? good[i][0].ff : 0) + 
                               ((b == 1 && q >= 2) ? good[i][1].ff : 0) + 
                               ((c == 1 && q == 3) ? good[i][2].ff : 0));
                    if (rest-v[i][0]-acc < 0) continue;
                    ll val = (((a == 1 && q >= 1) ? good[i][0].ff*good[i][0].ss : 0) + 
                               ((b == 1 && q >= 2) ? good[i][1].ff*good[i][1].ss : 0) + 
                               ((c == 1 && q == 3) ? good[i][2].ff*good[i][2].ss : 0));
                    ans = max (ans, aux+val+ dp (i+1, rest-v[i][0]-acc));
                }
            }
        }
    }
    return me[i][rest] = ans;
}

int main () {
    int t, v_max;
    scanf ("%d", &t);
    while (t--) {
        memset (me, -1, sizeof me);
        scanf ("%d %d", &v_max, &n);
        for (int i = 0; i < n; i++) good[i].clear ();
        for (int i = 0; i < n; i++) {
            scanf ("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
            if (v[i][2] != 0) good[v[i][2]-1].pb (pii (v[i][0], v[i][1]));
        }
        printf ("%lld\n", dp (0, v_max));
    }
}

