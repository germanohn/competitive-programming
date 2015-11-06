#include <bits/stdc++.h>
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n, e, t, m;
int dis[MAX];
bool vis[MAX];
vector<pii> adj[MAX];

void solve () {
    priority_queue<pii> p;
    dis[e] = 0;
    p.push (mp (0, e));
    while (!p.empty ()) {
        int x = p.top ().ss;
        p.pop ();
        /*if (vis[x]) 
            continue;
        vis[x] = true;*/
        for (int i = 0; i < adj[x].size (); i++) {
            pii next = adj[x][i];
            if (dis[next.ff] > dis[x] + next.ss) {
                dis[next.ff] = dis[x] + next.ss;
                p.push (mp (-dis[next.ff], next.ff));
            }
        }
    }
}

int main () {
    scanf ("%d %d %d %d", &n, &e, &t, &m);
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    int a, b, p;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d %d", &a, &b, &p);
        adj[a].pb (mp (b, p));
    }
    solve ();
    int cont = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] <= t) cont++;
    }
    printf ("%d\n", cont);
}
