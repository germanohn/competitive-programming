#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

int n, cont;
bool seen[N];
vector<int> adj[N], c[N];
set<int> s;

void add_freq(int u) {
    c[u].pb(cont);
    s.insert(cont++);
}

void get(int u, int v) {
    if (s.find(c[v][0]) != s.end()) {
        c[u].pb(c[v][0]);
        s.erase(c[v][0]);
    }
    else if (s.find(c[v][1]) != s.end()) {
        c[u].pb(c[v][1]);
        s.erase(c[v][1]);
    } else {
        c[u].pb(c[v][0]);
    }
}

void dfs(int u) {
    seen[u] = true;
    for (int i = 0; i < adj[u].size() && c[u].size() == 0; i++) {
        int v = adj[u][i];
        if (seen[v]) 
            get(u, v);
    }
    if (adj[u].size() == 1 && c[u].size() < 2) 
        get(u, adj[u][0]);

    while (c[u].size() < 2) {
        add_freq(u);
    }

    for (int v : adj[u]) {
        if (!seen[v])
            dfs(v);
    }
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            add_freq(i);
            add_freq(i);
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", c[i][0], c[i][1]);
    }
}
