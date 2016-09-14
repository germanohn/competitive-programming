#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 10004;

int n, m;
bool seen[MAX];
vector<int> adj[MAX];

bool dfs (int u, int p) {
    seen[u] = true;
    bool tree = true;
    for (int i = 0; true && i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (seen[v] && v != p) tree = false;
        else if (!seen[v] && v != p) dfs (v, u);
    }
    return tree;
}

int main() {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf (" %d %d", &u, &v);
        adj[u].pb (v);
        adj[v].pb (u);
    }

    bool ans = dfs (1, 0);
    for (int i = 1; ans && i <= n; i++) 
        if (!seen[i]) ans = false;
    if (ans) printf ("YES\n");
    else printf ("NO\n");
}

