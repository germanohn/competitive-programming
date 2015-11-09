/* faz um dijkstra de cada rato ate a saida e ve se passa no tempo
// Cuidado: primeiro tinha tentado fazer um dijkstra so da saida 
// para todos. Mas isso nao vale pois o grafo é direcionado*/
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
vector<pii> adj[MAX];

void solve (int no) {
    priority_queue<pii> p;
    dis[no] = 0;
    p.push (mp (0, no));
    while (!p.empty ()) {
        int x = p.top ().ss;
        p.pop ();
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
    int a, b, p;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d %d", &a, &b, &p);
        adj[a].pb (mp (b, p));
    }
    int cont = 1;
    for (int i = 1; i <= n; i++) {
        if (i != e) {
            for (int j = 1; j <= n; j++) {
                dis[j] = INT_MAX;
            }
            solve (i);
            if (dis[e] <= t) {
                cont++;
            }
        }
    }
    printf ("%d\n", cont);
}
