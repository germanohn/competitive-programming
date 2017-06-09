#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5;

int n;
int ans[N], degree[N], _xor[N];
vector<int> adj[N];

void solve() {
    queue<int> q;
    for (int i = 0; i < n; i++) 
        if (degree[i] == 1) 
            q.push(i), adj[i].pb(_xor[i]);
    
    int sz = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!degree[u]) continue;
        ans[sz++] = u;
        for (int v : adj[u]) {
            degree[v]--, _xor[v] ^= u;
            if (degree[v] == 1) 
                q.push(v), adj[v].pb(_xor[v]);
        }
    }
}

int main () {
    scanf(" %d", &n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        degree[i] = a;
        m += degree[i];
        _xor[i] = b;
    }

    solve();

    printf("%d\n", m / 2);
    for (int i = 0; i < (m / 2); i++) 
        printf("%d %d\n", ans[i], _xor[ans[i]]);
}

