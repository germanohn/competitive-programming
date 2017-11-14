#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e4 + 5;

int n, q, ind_pre, ind_pos;
int ci[N], pre[N], pos[N], par[N];
int _xor[N][2];
bool seen[N];
vector<int> adj[N];

void dfs(int u, int d) {
    seen[u] = true;
    par[u] = d;
    pre[u] = ind_pre++;
    for (int v : adj[u]) {
        if (!seen[v]) {
            dfs(v, (d + 1) % 2);
            _xor[u][0] ^= _xor[v][1];
            _xor[u][1] ^= _xor[v][0]; // xor impar
        }
    }
    _xor[u][0] ^= ci[u];
    pos[u] = ind_pos++;
}

// se b não é filho de a
bool is_valid(int a, int b) {
    if (pre[a] < pre[b] && pos[b] < pos[a]) return false;
    return true;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &ci[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);

    scanf(" %d", &q);
    while (q--) {
        int a, b;
        int ans = _xor[0][1];
        scanf(" %d %d", &a, &b);
        a--, b--;
        if (!is_valid(a, b)) printf("INVALID\n");
        else {
            int par_a = par[a], par_a2 = !par[b];
            if (par_a != par_a2) {
                ans ^= _xor[a][0]; // tira
                ans ^= _xor[a][1];
            }
            if (ans) printf("YES\n");
            else printf("NO\n");
        }
    }
}

