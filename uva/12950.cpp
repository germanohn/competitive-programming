#include <bits/stdc++.h>
#define MAX 10005
#define first peso
#define second node

using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[MAX];
int c, v, dis[MAX];

void solve (int ini) {
    priority_queue<pii> pq;
    pq.push (pii (0, ini));
    dis[ini] = 0;
    while (!pq.empty ()) {
        pii x;
        x = pq.top;
        x.pop ();
        if (
        for (int i = 0; i < adj[x.node].size (); i++) {
            if (
        }
    }
}

int main () {
    scanf ("%d %d", &c, &v);
    for (int i = 0; i < v; i++) {
       scanf ("%d %d %d", &a, &b, &c);
       adj[a].pb (mp (c, b + v));
       adj[a + v].pb (mp (c, b));
       adj[b].pb (mp (c, a + v));
       adj[b + v].pb (mp (c, a));
    }
    solve ();

}


