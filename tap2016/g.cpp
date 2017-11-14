#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
const int T = 31 * N;

struct edge {
    int v, w;

    edge(int v, int w) : v(v), w(w) {}
};

int n, k;
int _xor[N];
int trie[T][2];
bool seen[N];
vector<edge> adj[N];

void add(int val) {
    int v = 0;
    for (int i = 31; i >= 0; i--) {
        int e = (val >> i) & 1;
        if (trie[v][e] == 0)
           trie[v][e] = k++;
        v = trie[v][e]; 
    }
}

void calc_xor(int u, int xor_acc) {
    seen[u] = true;
    for (auto e : adj[u]) {
        if (!seen[e.v]) {
            _xor[e.v] = xor_acc ^ e.w;
            calc_xor(e.v, _xor[e.v]);
        }
    }
}

int max_value(int val) {
    int v = 0, ans = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (val >> i) & 1;
        if (trie[v][!bit]) {
            ans += (1 << i);
            v = trie[v][!bit];
        } else {
            v = trie[v][bit];
        }
    }
    
    return ans;
}

void init() {
    k = 1;
    for (int i = 0; i < n; i++) 
        adj[i].clear(), _xor[i] = 0, seen[i] = 0;
    memset(trie, 0, sizeof trie);
}

int main() {
    while (scanf(" %d", &n) != EOF) {
        init();
        for (int i = 0; i < n - 1; i++) {
            int a, b, c;
            scanf(" %d %d %d", &a, &b, &c);
            a--, b--;
            adj[a].pb(edge(b, c));
            adj[b].pb(edge(a, c));
        }

        calc_xor(0, 0);
        for (int i = 0; i < n; i++) 
            add(_xor[i]);

        for (int i = 0; i < n; i++) 
            printf("%d\n", max_value(_xor[i]));
    }
}

