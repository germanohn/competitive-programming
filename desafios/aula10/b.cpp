#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 1000005;
const int inf = 1e9;

int f, s, g, u, d;
int dis[MAX];

void bfs () {
    queue<int> q;
    q.push (s);
    dis[s] = 0;
    int cont = 0;
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        bool ent = false;
        if (x+u <= f && dis[x+u] > dis[x]+1) {
            dis[x+u] = cont+1;
            q.push (x+u);
            ent = true;
        }
        if (x-d >= 1 && dis[x-d] > dis[x]+1) {
            dis[x-d] = cont+1;
            q.push (x-d);
            ent = true;
        }
        if (ent) cont++;
    }
}

int main () {
    scanf ("%d %d %d %d %d", &f, &s, &g, &u, &d);
    for (int i = 1; i <= f; i++) dis[i] = inf;
    bfs ();
    if (dis[g] != inf) printf ("%d\n", dis[g]);
    else printf ("use the stairs\n");
}
