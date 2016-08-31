#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 100005;
const ll inf = 1e14;

struct tii {
    tii () {}
    tii (int no, int ed, int idd) {
        node = no, edge = ed, id = idd;
    }
    int node, id;
    ll edge;
};

int n, m, s, t, tempo;
int d[MAX], low[MAX];
int vp[MAX][5];
ll dis[MAX], dis_rev[MAX];
bool seen[MAX];
vector<int> ponte;
vector<tii> adj[MAX], adj_min[MAX];
vector<pli> adj_rev[MAX];

void dfs_ponte (int u, int p) {
    seen[u] = true;
    d[u] = low[u] = tempo++;
    for (tii v : adj_min[u]) {
        if (!seen[v.node]) {
            dfs_ponte (v.node, u);
            low[u] = min (low[u], low[v.node]);
            if (low[v.node] == d[v.node]) 
                ponte.pb (v.id);
        } else if (v.node != p) {
            low[u] = min (low[u], d[v.node]);            
        } 
        if (v.node == p) p = -1;
    }

}

void dijkstra () {
    priority_queue<pli> pq;
    dis[s] = 0;
    pq.push (pli (0, s));
    while (!pq.empty ()) {
        pli x = pq.top ();
        pq.pop ();
        if (seen[x.ss]) continue;
        seen[x.ss] = true;
        for (tii nx : adj[x.ss]) {
            if (dis[nx.node] > dis[x.ss] + nx.edge) {
                dis[nx.node] = dis[x.ss] + nx.edge;
                pq.push (pli (-dis[nx.node], nx.node));
            }
        }
    }
}

void dijkstra_rev () {
    priority_queue<pli> pq;
    dis_rev[t] = 0;
    pq.push (pli (0, t));
    while (!pq.empty ()) {
        pli x = pq.top ();
        pq.pop ();
        if (seen[x.ss]) continue;
        seen[x.ss] = true;
        for (pli nx : adj_rev[x.ss]) {
            if (dis_rev[nx.ff] > dis_rev[x.ss] + nx.ss) {
                dis_rev[nx.ff] = dis_rev[x.ss] + nx.ss;
                pq.push (pli (-dis_rev[nx.ff], nx.ff));
            }
        }
    }
}

void dfs (int u) {
    seen[u] = true;
    for (tii v : adj[u]) {
        if (dis[u]+v.edge+dis_rev[v.node] == dis[t]) {
            adj_min[u].pb (tii (v.node, v.edge, v.id));
            adj_min[v.node].pb (tii (u, v.edge, v.id));
            if (!seen[v.node]) dfs (v.node);
        }
    }
}

int main () {
    tempo = 0;
    scanf (" %d %d %d %d", &n, &m, &s, &t);
    s--, t--;
    for (int i = 0; i < n; i++) 
        dis[i] = dis_rev[i] = inf;

    for (int i = 0; i < m; i++) {
        int u, v, l;
        scanf (" %d %d %d", &u, &v, &l);
        u--, v--;
        vp[i][0] = u, vp[i][1] = v, vp[i][2] = l;
        adj[u].pb (tii (v, l, i));
        adj_rev[v].pb (pli (u, l));
    }

    dijkstra ();
    for (int i = 0; i < n; i++) seen[i] = false;
    dijkstra_rev ();

    for (int i = 0; i < n; i++) seen[i] = false;
    dfs (s);

    for (int i = 0; i < n; i++) seen[i] = false;
    dfs_ponte (s, -1);

    int size_pte = ponte.size ();
    sort (ponte.begin (), ponte.end ());
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (k < size_pte && ponte[k] == i) {
            printf ("YES\n");
            k++;
        } else {
            int u, v;
            ll dif, l;
            u = vp[i][0], v = vp[i][1], l = vp[i][2];
            dif = dis[t] - (dis[u]+dis_rev[v]);
            if (dif >= 2) {
                printf ("CAN %lld\n", l-(dif-1));
            } else {
                printf ("NO\n");
            }
        }
    }
}




