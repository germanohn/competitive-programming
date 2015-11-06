#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

int n, m, c, k, u, v, p;
int dis[300], rota[300];
bool vis[300];
vector<pii> adj[300];

void solve (int no) {
    priority_queue<pii> p;
    dis[no] = 0;
    p.push (mp (0, no));
    while (!p.empty ()) {
        int x = p.top ().ss;
        p.pop ();
        if (vis[x])
            continue;
        vis[x] = true;
        if (x < c-1) {
            if (dis[c-1] > dis[x] + rota[x])
                dis[c-1] = dis[x] + rota[x];
        }
        else {
            for (int i = 0; i < adj[x].size (); i++) {
                pii next = adj[x][i];
                if (dis[next.ff] > dis[x] + next.ss) {
                    dis[next.ff] = dis[x] + next.ss;
                    p.push (mp (-dis[next.ff], next.ff));
                }
            }
        }    
    }    
}

int main () {
    while (scanf ("%d %d %d %d", &n, &m, &c, &k) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) {
            vis[i] = false;
            dis[i] = INT_MAX;
            adj[i].clear ();
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &u, &v, &p);
            if (u < v) swap (u, v);
            if (u - v == 1) {
                rota[v] = p;
            }
            adj[u].pb (mp (v, p));
            adj[v].pb (mp (u, p));
        }
        rota[c-1] = 0;
        for (int i = c-2; i >= 0; i--) {
            rota[i] += rota[i+1];
        }
        solve (k);
        printf ("%d\n", dis[c-1]);
    }
}
