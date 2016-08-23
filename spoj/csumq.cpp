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
int st[MAX][30], v[MAX];

void init () {
    for (int i = n-1; i >= 0; i--) {
        st[i][0] = v[i];
        for (int j = 1; j < 20; j++) {
            int pot = (1 << j);
            if (i+pot-1 >= n) break;
            st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
        }
    }
}

ll query (int l, int r) {
    ll ans = 0;
    for (int k = 20; k >= 0; k--) {
        if (l+(1<<k)-1 > r) continue;
        ans += st[l][k];
        l += (1<<k);
    }
    return ans;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    init ();
    int q;
    scanf ("%d", &q);
    int l, r;
    ll ans;
    while (q--) {
        scanf ("%d %d", &l, &r);
        ans = query (l, r);
        printf ("%lld\n", ans);
    }
}

