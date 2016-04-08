#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, k;
bool vis[100005], door[100005], ok[100005];
int key[100005];
vector<int> adj[1000005];

void bfs () {
    vis[1] = true;
    queue<int> q;
    q.push (1);
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        for (int i = 0; i < adj[x].size (); i++) {
            int nx = adj[x][i];
            if (!vis[nx]) {
                if (key[nx]) {
                    ok[key[nx]] = true;
                    if (vis[key[nx]])
                        q.push (key[nx]);
                    q.push (nx);
                } else if (door[nx]) {
                    if (ok[nx]) 
                        q.push (nx);
                } else q.push (nx);
                vis[nx] = true;
            }
        }
    }
}

int main () {
    while (scanf ("%d %d %d", &n, &k, &m) && n != -1 && k != -1 && m != -1) {        
        int a, b;
        for (int i = 0; i <= n; i++) 
            vis[i] = false, ok[i] = false, door[i] = false, key[i] = 0, adj[i].clear ();
        for (int i = 0; i < k; i++) {
            scanf ("%d %d", &a, &b);
            key[a] = b, door[b] = true; 
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b);
            adj[a].pb (b);
            adj[b].pb (a);
        }
        bfs ();
        //for (int i = 1; i <= n; i++) {
          //  printf ("i %d vis %d ok %d door %d key %d\n", i, vis[i], ok[i], door[i], key[i]);
        //}
        //printf ("\n");
        if (vis[n]) printf ("Y\n");
        else printf ("N\n");
    }
}
