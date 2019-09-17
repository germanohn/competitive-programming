#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

vector<int> adj[N];

int main() {
    int n;
    scanf(" %d", &n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        ok = adj[i].size() != 2;
    }

    printf("%s\n", ok ? "YES": "NO");
}

