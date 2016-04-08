#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 1005;

int n, m;
vector<int> adj[MAX];
int vis[MAX];

void dfs (int no) {
    vis[no] = true;
    for (int i = 0; i < adj[no].size (); i++) {
        int nx = adj[no][i];
        if (!vis[nx]) 
            dfs (nx);
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        adj[a].pb (b);
        adj[b].pb (a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) 
            dfs (i), ans++;
    }
    printf ("%d\n", ans);
}

