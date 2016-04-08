#include <bits/stdc++.h>
#define next first
#define cost second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 505;

int n, e, sn, tempo;
int d[MAX], low[MAX], st[MAX], comp[MAX], dis[MAX];
bool seen[MAX];
vector<pii> adj[MAX];

void dfs (int u) {
    seen[u] = true;
    st[sn++] = u;
    d[u] = low[u] = tempo++;
    for (int i = 0; i < adj[u].size (); i++) {
        pii v = adj[u][i];
        if (!seen[v.next]) {
            dfs (v.next);
            low[u] = min (low[u], low[v.next]);
        } else {
            low[u] = min (low[u], low[v.next]);
        }
    }
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sn];
            comp[a] = u;
            low[a] = INT_MAX;
        } while (a != u); 
    }
}

void dijkstra (int u) {
    priority_queue<pii> q;
    dis[u] = 0;
    q.push (pii (0, u));
    while (!q.empty ()) {
        // u é o vertice
        int u = q.top ().cost;
        q.pop ();
        for (int i = 0; i < adj[u].size (); i++) {
            pii nw = adj[u][i];
            int cost;
            if (comp[u] == comp[nw.next])
               cost = 0;
            else 
               cost = nw.cost; 
            if (dis[nw.next] > dis[u]+cost) {
                dis[nw.next] = dis[u]+cost;
                q.push (pii (-dis[nw.next], nw.next));
            }
        }
    }
}

int main () {
    while (scanf ("%d %d", &n, &e) && n != 0) {
        sn = tempo = 0;
        int x, y, h;
        for (int i = 1; i <= n; i++) 
            seen[i] = false, adj[i].clear ();
        for (int i = 0; i < e; i++) {
            scanf ("%d %d %d", &x, &y, &h);
            adj[x].pb (pii (y, h));
        }
        for (int i = 1; i <= n; i++) {
            if (!seen[i])
                dfs (i);
        }
        int k, ori, des;
        scanf ("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf ("%d %d", &ori, &des);    
            for (int j = 1; j <= n; j++) 
                dis[j] = INT_MAX;
            dijkstra (ori);
            if (dis[des] == INT_MAX) 
                printf ("Nao e possivel entregar a carta\n");
            else 
                printf ("%d\n", dis[des]);
        }
        printf ("\n");
    }
}









