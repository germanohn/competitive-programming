#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int k, w, numKid;
bool seen[MAX];
set<int> adj[MAX];
map<int, int> kid;

bool cycle (int u, int p) {
    seen[u] = true;
    numKid++;
    bool ans = false;
    set<int>::iterator it;
    for (it = adj[u].begin (); it != adj[u].end (); it++) {
        int v = *it;
        if (v != p && seen[v])
            ans = true;
        else if (v != p && !seen[v]) 
            ans = cycle (v, u);
    }
    return ans;
}

int main () {
    while (scanf ("%d %d", &k, &w)) {
        if (k == 0 && w == 0) 
            break;
        
        for (int i = 0; i < 2*w; i++) 
            seen[i] = false, adj[i].clear ();
        kid.clear ();

        int val = 0, u, v;
        for (int i = 0; i < w; i++) {
            scanf ("%d %d", &u, &v);
            if (kid.find (u) == kid.end ()) 
                kid[u] = val++;
            if (kid.find (v) == kid.end ())
                kid[v] = val++;
            u = kid[u], v = kid[v];
            adj[u].insert (v);
            adj[v].insert (u);
        }

        bool f = true;
        for (int i = 0; f && i < val; i++) 
            if (adj[i].size () > 2) {
                f = false;
                printf ("N\n");
            }
        
        if (!f) 
            continue;
        f = true;
        for (int i = 0; i < val; i++) {
            if (!seen[i]) {
                numKid = 0;
                if (cycle (i, -1)) {
                    if (numKid < k) 
                        f = false;
                    break;
                }
            }
        }
        if (f) {
            printf ("Y\n");
        } else {
            printf ("N\n");
        }
    }
}

