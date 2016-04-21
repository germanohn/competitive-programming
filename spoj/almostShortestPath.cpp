#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1000000000;
const int MAX = 505;

int n, m, s, des, u, v, p;
int d[MAX], forbid[MAX][MAX];
bool vis[MAX];
vector<pii> adj[MAX], adjR[MAX];

void dijkstra () {
    priority_queue<pii> pq;
    pq.push (pii (0, s));
    d[s] = 0;
    while (!pq.empty ()) {
        int u = pq.top ().ss;
        pq.pop ();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < adj[u].size (); i++) {
            int v = adj[u][i].ff;
            int edge = adj[u][i].ss;
            if (!forbid[u][v] && d[v] > d[u] + edge) {
                d[v] = d[u] + edge;
                pq.push (pii (-d[v], v));
            }
        }
    }   
}

void bfs () {
    queue<int> q;
    q.push (des);
    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();
        for (int i = 0; i < adjR[u].size (); i++) {
            int v = adjR[u][i].ff;
            int edge = adjR[u][i].ss;
            if (d[v] + edge == d[u]) {
                if (!vis[v]) q.push (v);
                forbid[v][u] = true;
                vis[v] = true;
            }
        }
    }
}

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        scanf ("%d %d", &s, &des);
        for (int i = 0; i <= n; i++) { 
            adj[i].clear (), adjR[i].clear (), d[i] = inf, vis[i] = false;
            for (int j = 0; j <= n; j++) 
                forbid[i][j] = false;
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &u, &v, &p);
            adj[u].pb (pii (v, p));
            adjR[v].pb (pii (u, p));
        }
        dijkstra ();
        for (int i = 0; i <= n; i++) 
            vis[i] = false;
        bfs ();
        for (int i = 0; i <= n; i++) 
            vis[i] = false, d[i] = inf;
        dijkstra ();
        if (d[des] == inf)
            printf ("-1\n");
        else 
            printf ("%d\n", d[des]);
    }
}

