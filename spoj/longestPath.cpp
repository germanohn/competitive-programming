#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair

using namespace std;

int n, a, b, dis[MAX], ans; 

vector<int> adj[MAX];

void bfs (int ini) {
    queue<int> q; 
    q.push (ini);
    dis[ini] = 0;
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        for (int i = 0; i < adj[x].size (); i++) {
            int u = adj[x][i];
            if (dis[u] > dis[x] + 1) {
                dis[u] = dis[x] + 1;
                q.push (u);
            }
        }
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf ("%d %d", &a, &b);
        adj[a].pb (b);
        adj[b].pb (a);
    }
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    bfs (a);
    int maxi = 0, ind;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > maxi) {
            maxi = dis[i];
            ind = i;
        }   
    }
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    bfs (ind);   
    maxi = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > maxi) {
            maxi = dis[i];
            ind = i;
        }   
    }
    
    ans = dis[ind];
    printf ("%d\n", ans);

}
