#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 1e5+5;

int n, ans, qtdSeen, turn;
int vp[MAX], qtdTree[MAX], seen[MAX];
vector<pii> adj[MAX];

void solve (int u, ll acc) {
    qtdSeen++;
    seen[u] = turn;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i].ff;
        ll edge = (ll) adj[u][i].ss;
        if (seen[v] != turn) {
            ll mx = max (edge, acc+edge);
            if (mx <= vp[v]) {
                solve (v, mx);
            }
        }
    }    
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf ("%d", &vp[i]);
    int p, c;
    for (int i = 1; i < n; i++) {
        scanf ("%d %d", &p, &c);
        adj[i+1].pb (pii (p, c));
        adj[p].pb (pii (i+1, c));
    }    
    turn = 1;
    solve (1, 0);
    ans = n-qtdSeen;
    printf ("%d\n", ans);
}

