#include <bits/stdc++.h>
#define MAX 10005
#define peso first
#define node second
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[2*MAX];
int c, w, v, dis[2*MAX], a, b;

void solve (int ini) {
    set<pii> s;
    s.insert (pii (0, ini));
    dis[ini] = 0;
    while (s.size ()) {
        int x, y;
        x = s.begin () -> peso;
        y = s.begin () -> node;
        s.erase (s.begin ());
        if (x > dis[y])
            continue;
        for (int i = 0; i < adj[y].size (); i++) {
            pii next = adj[y][i];
            if (dis[next.node] > dis[y] + next.peso) {
                dis[next.node] = dis[y] + next.peso;
                s.insert (pii (dis[next.node], next.node));
            }
        }
            
    } 
}

int main () {
    while (scanf ("%d %d", &w, &v) != EOF) {
         for (int i = 1; i <= 2 * w; i++) { 
            dis[i] = INT_MAX;
            adj[i].clear ();
        }



        for (int i = 0; i < v; i++) {
            scanf ("%d %d %d", &a, &b, &c);
            adj[a].pb (mp (c, b + w));
            adj[a + w].pb (mp (c, b));
            adj[b].pb (mp (c, a + w));
            adj[b + w].pb (mp (c, a));
        }
               solve (1);
        if (dis[w] == INT_MAX) printf ("-1\n");
        else printf ("%d\n", dis[w]);

    }
}

