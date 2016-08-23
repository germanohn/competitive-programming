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

int n, q;
int v[MAX];
int st[MAX][30];

void init () {
    for (int i = n-1; i >= 0; i--) {
        st[i][0] = v[i];
        for (int j = 1; j < 20; j++) {
            int pot = (1 << j);
            if (i+pot-1 >= n) break;
            st[i][j] = min (st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int query (int l, int r) {
    int size = r-l+1, ans;
    int k = 32-1-__builtin_clz (size);
    ans = min (st[l][k], st[r-(1<<k)+1][k]);
    return ans;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    init ();
    scanf ("%d", &q);
    int l, r, ans;
    while (q--) {
        scanf ("%d %d", &l, &r);
        ans = query (l, r);
        printf ("%d\n", ans);
    }
}

