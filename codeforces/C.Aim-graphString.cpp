#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 505;

int n, m, qa, qb, qc, grau[MAX], vis[MAX];
vector<int> adj[MAX];

void dfs (int no, int val) {
    if (val == 'a') qa++;
    else if (val == 'c') qc++;
    vis[no] = val;
    for (int i = 0; i < adj[no].size (); i++) {
        int nx = adj[no][i];
        if (!vis[nx]) 
            dfs (nx, val);
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        adj[a].pb (b);
        adj[b].pb (a);
        grau[a]++;
        grau[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && grau[i] == n-1) 
            vis[i] = 'b', qb++;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i, 'a');
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i, 'c');
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] || (vis[i] == 'a' && grau[i] != qb + qa -1) ||
           (vis[i] == 'c' && grau[i] != qb + qc -1)) {
            printf ("No\n");
            return 0;
        }
    }
    printf ("Yes\n");
    for (int i = 1; i <= n; i++) 
        printf ("%c", vis[i]);
    printf ("\n");
}














