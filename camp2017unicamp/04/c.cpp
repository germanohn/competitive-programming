#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000006;

int n, lab;
int color[MAX], sz[MAX];
ll w[MAX], a[MAX], b[MAX], v[MAX], mass[MAX], mini[MAX];
vector<int> adj[MAX];

void dfs(int u, int lab) {
    color[u] = lab;
    sz[lab]++;
    mass[lab] += w[u];
    mini[lab] = min(mini[lab], w[u]);
    for (int v : adj[u]) {
        if (color[v] == -1) 
            dfs(v, lab);
    } 
}

int main () {
    memset(color, -1, sizeof color);
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        mini[i] = MAX;
    }
    for (int i = 0; i < n; i++) { 
        int u;
        scanf(" %d", &u);
        u--;
        a[u] = i;
    }
    for (int i = 0; i < n; i++) 
        w[a[i]] = v[i];
    for (int i = 0; i < n; i++) {
        int u;
        scanf(" %d", &u);
        u--;
        b[u] = i;
    }
    for (int i = 0; i < n; i++) 
        adj[a[i]].pb(b[i]);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { 
            dfs(i, lab);
            lab++;
        }
    }
    ll mg = *min_element(mini, mini+lab);
    for(int i = 0; i < lab; i++) {
        ll df = (mass[i] - mini[i] + ll(sz[i] - 1) * mg) + 2ll*(mg + mini[i]);
        ans += min((mass[i] - mini[i] + ll(sz[i] - 1) * mini[i]), df);
    }
    printf("%lld\n", ans);
}

