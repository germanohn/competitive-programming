#include <bits/stdc++.h>
#define MAX 10005
#define peso first
#define node second
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[MAX];
int c, w, v, dis[MAX], a, b;

void solve (int ini) {
    priority_queue<pii> pq;
    pq.push (pii (0, ini));
    dis[ini] = 0;
    int cont = 10;
    while (!pq.empty ()) {
        int x, y;
        x = pq.top ().node;
        y = pq.top ().peso;
        printf ("x %d y %d\n",x, y);
        pq.pop ();
        if (!cont) return; 
        if (y > dis[x])
            continue;
        for (int i = 0; i < adj[x].size (); i++) {
            pii next = adj[x][i];
            if (dis[next.node] > dis[x] + next.peso) {
                dis[next.node] = dis[x] + next.peso;
                pq.push (pii (dis[next.node], next.node));
            }
        }
        cont--;
    }
}

int main () {
    scanf ("%d %d", &w, &v);
    for (int i = 0; i < v; i++) {
       scanf ("%d %d %d", &a, &b, &c);
       adj[a].pb (mp (-c, b + v));
       adj[a + v].pb (mp (-c, b));
       adj[b].pb (mp (-c, a + v));
       adj[b + v].pb (mp (-c, a));
    }
    for (int i = 1; i <= v; i++) 
        dis[i] = INT_MAX;
   
    solve (1);
    if (dis[v] == INT_MAX) printf ("-1\n");
    else printf ("%d\n", -dis[v]);
}


