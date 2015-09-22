#include <bits/stdc++.h>
#define pb push_back
#define MAX 100005

using namespace std;

int n, m, cat[MAX], cont, a, b;
bool vis[MAX];
vector<int> adj[MAX];

void dfs (int s, int sum) {
    vis[s] = true;
    if (sum > m) return;
    bool f = true;
    for (int i = 0; i < adj[s].size (); i++) {
        a = adj[s][i];
        if (!vis[a]) {
            f = false;
            if (!cat[a]) 
                dfs (a, 0);
            else
                dfs (a, sum + cat[a]);    
        }
    }
    if (f) 
        cont++;
   
} 

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    for (int i = 1; i <= n; i++)
        scanf ("%d", &cat[i]);
    for (int i = 0; i < n - 1; i++) {
        scanf ("%d %d", &a, &b);
        adj[a].pb (b);
        adj[b].pb (a);
    }
    dfs (1, cat[1]);
    printf ("%d\n", cont);
}
