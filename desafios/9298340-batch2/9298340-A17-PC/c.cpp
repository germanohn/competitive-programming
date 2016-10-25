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

const int MAX = 100005;

int n;
ll v[MAX], freq[MAX];
ll me[MAX][3];

ll dp (int i, int has_to) {
    if (i == n) return 0;
    if (me[i][has_to] != -1) return me[i][has_to];

    ll ans;
    int nx = i + freq[v[i]];
    if (has_to) {
        ans = freq[v[i]] * v[i];
        if (v[nx] == v[i] + 1) {
            ans += dp (nx + freq[v[nx]], 0);
        } else {
            ans += dp (nx, 0);
        }
    } else {
        if (v[nx] == v[i] + 1) {
            ans = max (freq[v[i]] * v[i] + dp (nx + freq[v[nx]], 0), 
                       dp (nx, 1));
        } else {
            ans = freq[v[i]] * v[i] + dp (nx, 0);
        }
    }

    return me[i][has_to] = ans;
}

int main () {
    scanf ("%d", &n);
    memset (me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        scanf (" %d", &v[i]);
        freq[v[i]]++;
    }

    v[n] = MAX - 1;

    sort (v, v+n);

    printf ("%lld\n", dp (0, 0));
}

