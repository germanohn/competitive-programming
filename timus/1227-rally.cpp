#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int m, n, s;
int vis[MAX], d[MAX];
vector<pii> adj[MAX];

int cycle (int no, int pai) {
    if (vis[no]) return 1;
    vis[no] = true;
    int ans = 0;
    for (int i = 0; i < adj[no].size (); i++) {
        int nx = adj[no][i].ff;
        if (nx != pai) ans= cycle (nx, no);
    }
    return ans;
}

void dfs (int no, int pai, int acc) {
    d[no] = acc;
    for (int i = 0; i < adj[no].size (); i++) {
        pii nx = adj[no][i];
        if (nx.ff != pai) {
            d[nx.ff] = d[no] + nx.ss;
            dfs (nx.ff, no, d[nx.ff]);
        }    
    }
}

int main () {
    scanf ("%d %d %d", &m, &n, &s);
    int a, b, w;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &a, &b, &w);
        a--, b--;
        adj[a].pb (mp (b, w));
        adj[b].pb (mp (a, w));
    }    
    int arv[MAX], k = 0;
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            arv[k++] = i;
            if (cycle (i, -1)) {
                printf ("YES\n");
                return 0;
            }

        }
    }
    int ma = -1, tmp, ind;
    for (int i = 0; i < k; i++) {
        tmp = -1;
        memset (d, 0, sizeof (d));
        dfs (arv[i], -1, 0);
        for (int j = 0; j < m; j++) { 
            if (d[j] > tmp) {
                tmp = d[j];
                ind = j;
            }
        }
        dfs (ind, -1, 0);
        for (int j = 0; j < m; j++) 
            if (d[j] > tmp) tmp = d[j];
        if (tmp > ma) ma = tmp; 
    }
    if (ma >= s) printf ("YES\n");
    else printf ("NO\n");
}
