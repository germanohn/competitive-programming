#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

int n;
double ans;
bool seen[N];
vector<int> adj[N];

void dfs(int u, double prob, int d) {
    seen[u] = true;
    
    int cont = 0;
    for (auto v : adj[u]) {
        if (!seen[v]) {
            cont++;
        }
    }

    if (!cont) {
        ans += prob * double(d);
    } else {
        for (auto v : adj[u]) {
            if (!seen[v]) {
                dfs(v, prob / double(cont), d + 1);
            }
        }
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

    dfs(0, 1., 0);
    printf("%.8lf\n", ans);
}

