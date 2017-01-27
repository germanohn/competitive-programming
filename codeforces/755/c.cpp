#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 10005;

int n;
bool seen[MAX];
vector<int> adj[MAX];

void dfs(int u) {
    seen[u] = true;
    for (auto v : adj[u]) {
        if (!seen[v]) 
            dfs(v);
    }
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        a--;
        adj[a].pb(i);
        adj[i].pb(a);
    }
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(i);
            cont++;
        }
    }
    printf("%d\n", cont);
}

