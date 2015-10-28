#include <bits/stdc++.h>
using namespace std;

int grau[100005], k, w, a, b, cont, flag;
map<int, int> m;
vector<int> adj[100005];

void dfs (int node, int p) {
    vis[node] = true;
    cont++;
    for (int i = 0; i < adj[node].size (); i++) {
        int aux = adj[node][i];
        if (vis[aux] && aux != p)
            flag = true;
        if (!vis[aux])
            dfs (aux, node);
    }
}

int main () {
    while (scanf ("%d %d", &k, &w) && k != 0 && w != 0) {
        int l = 0;
        bool f = true;
        flag = false;
        m.clear ();
        for (int i = 0; i < 100005; i++) {
            adj[i].clear ();
            grau[i] = 0;
            vis[i] = false;
        }
        for (int i = 0; i < w; i++) {
            scanf ("%d %d", &a, &b);
            if (!m[a]) m[a] = l++;
            if (!m[b]) m[b] = l++;
            adj[m[a]].pb (m[b]);
            adj[m[b]].pb (m[a]);
            grau[m[a]]++;
            grau[m[b]]++;
            if (grau[m[a]] > 2 || grau[m[b]] > 2) {
                printf ("N\n");
                f = false;
            }
        }
        if (f) {
            for (int i = 0; i < l; i++) {
                cont = 0;
                if (!vis[i]) { 
                    dfs (i, -1);
                    if (flag) {
                        if (cont == k) {
                            printf ("Y\n");
                            continue;
                        }
                        else {
                            printf ("N\n");
                            continue;
                        }
                    }
                }
            }
            printf ("Y\n");    
        }
    }
}
