#include <bits/stdc++.h>
#define pb push_back 
using namespace std;

int c, r, cont, maxi;
bool vis[5005];
string s, ss;
map<string, int> m;
vector<int> adj[5005];

void dfs (int node) {
    vis[node] = true;
    cont++;
    for (int i = 0; i < adj[node].size (); i++) {
        int a = adj[node][i];
        if (!vis[a]) {
            dfs (a);
        }
    } 
}

int main () {
    while (scanf ("%d %d", &c, &r) && c != 0) {
        m.clear ();
        for (int i = 0; i < c; i++)
            adj[i].clear ();
        int k = 0;
        for (int i = 0; i < c; i++)
            vis[i] = false;
        for (int i = 0; i < c; i++) {
            cin >> s;
            m[s] = k++;
        }
        for (int i = 0; i < r; i++) {
            cin >> s >> ss;
            adj[m[s]].pb (m[ss]);
            adj[m[ss]].pb (m[s]);
        }
        maxi = 1;
        for (int i = 0; i < c; i++) {
            cont = 0;
            if (!vis[i]) {
                dfs (i);
                if (cont > maxi) maxi = cont;
            }
        }
        printf ("%d\n", maxi);
    }
}
