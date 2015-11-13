#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAX = 30;

int n, v, e;
bool vis[MAX];
set<int> s;
vector<int> adj[MAX];

void dfs (int no, int pai) {
    vis[no] = true;
    s.insert (no);
    for (int i = 0; i < adj[no].size (); i++) {
        int nx = adj[no][i];
        if (!vis[nx]) dfs (nx, no);
    }
}

int main () {
    scanf ("%d", &n);
    int cont = 1;
    while(n--){
        scanf ("%d %d", &v, &e);
        for (int i = 0; i < v; i++)
            vis[i] = false;
        for (int i = 0; i < MAX; i++)
            adj[i].clear ();
        map<char, int> m;
        for (int i = 0; i < e; i++) {
            char a, b;
            scanf (" %c %c", &a, &b);
            if (m.find (a) == m.end ()) m[a] = a-'a';
            if (m.find (b) == m.end ()) m[b] = b-'a';
            adj[m[a]].pb (m[b]);
            adj[m[b]].pb (m[a]);
        }
        int quant = 0;
        printf ("Case #%d:\n", cont++);
        for (int i = 0; i < v; i++) {
            s.clear ();
            if (!vis[i]) {
                quant++;
                dfs (i, -1);
                set<int>::iterator i;
                for (i = s.begin (); i != s.end (); i++) {
                    printf ("%c,", *i+'a');
                }
                printf ("\n");
            }
        }
        printf ("%d connected components\n\n", quant);
    }
}
