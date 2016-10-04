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

const int MAX = 5005;
const int inf = 1e9;

int n, m, t;
pii l[MAX], r[MAX], mid[MAX];
vector<pii> adj[MAX];

void dfs (int u, int q_vert, int q_tempo) {
    if (u == n) 
       return; 

    printf ("u %d q_vert %d size %d\n", u, q_vert, adj[u].size ());
    for (int i = 0; i < adj[u].size (); i++) {
        pii v = adj[u][i];
        printf ("antes\n");
        if (q_tempo + v.ss > t) continue;
        printf ("oi\n");
        if (q_vert+1 > mid[v.ff].ff && q_tempo + v.ss < mid[v.ff].ss) {
           dfs (v.ff, q_vert+1, q_tempo+v.ss);
           mid[v.ff].ff = q_vert+1;
           mid[v.ff].ss = q_tempo + v.ss;
        } else if (q_vert+1 <= mid[vq_vert+1 > l[v.ff].ff && q_tempo + v.ss < l[v.ff].ss) {
           dfs (v.ff, q_vert+1, q_tempo+v.ss);
           l[v.ff].ff = q_vert+1;
           l[v.ff].ss = q_tempo + v.ss; 
        } 
        if (q_vert+1 > r[v.ff].ff && q_tempo + v.ss < r[v.ff].ss) {
           dfs (v.ff, q_vert+1, q_tempo+v.ss);
           r[v.ff].ff = q_vert+1;
           r[v.ff].ss = q_tempo + v.ss; 
        }
    }   
}
/*
void dfs2 (int u, int ff, int q_tempo) {
    if (u == n) return;

    for (int i = 0; i < adj[u].size (); i++) {
        pii v = adj[u][i];
        if (v.q_
    }   
}*/

int main () {
    scanf ("%d %d %d", &n, &m, &t);
    for (int i = 0; i < m; i++) {
        int u, v, tempo;
        scanf ("%d %d %d", &u, &v, &tempo);
        u--, v--;
        printf ("u %d v %d\n", u, v);
        adj[u].pb (pii (v, tempo));
    }   
    
    for (int i = 0; i < n; i++) {
        mid[i].ff = l[i].ff = r[i].ff = 0;
        mid[i].ss = l[i].ss = r[i].ss = inf;
    }

    dfs (0, 1, 0);

    int ans = mid[n].ff;
    printf ("ans %d\n", ans);

}

