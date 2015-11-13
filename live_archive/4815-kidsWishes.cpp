#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first 
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 200005;

int w;
ll k, a, b, quant; 
set<int> adj[MAX];
ll vis[MAX];
map<ll, ll> m;

int cycle (int no, int pai) {
    if (vis[no]) return 1;
    quant++;
    vis[no] = true;
    int ans = 0;
    set<int>::iterator i;
    for (i = adj[no].begin (); i != adj[no].end (); i++) {
        ll nx = *i;
        if (nx != pai) {
            ans += cycle (nx, no);
        }
    }
    return ans;
}

int main () {
    while (scanf ("%lld %d", &k, &w) && (k != 0 || w != 0)) {
        for (int i = 0; i < MAX; i++) {
            vis[i] = false;
            adj[i].clear ();
        }
        m.clear ();
        int l = 0, i;        
        for (i = 0; i < w; i++) {
            scanf ("%lld %lld", &a, &b);
            if (m.find (a) == m.end ()) m[a] = l++; 
            if (m.find (b) == m.end ()) m[b] = l++;
            a = m[a], b = m[b];
            adj[a].insert (b);
            adj[b].insert (a);
        }
        for (i = 0; i < l; i++) {
            if (adj[i].size () > 2) {
                printf ("N\n");
                break;
            }
        }
        if (i != l) continue;
        for (i = 0; i < l; i++) {
            if (!vis[i]) {
                quant = 0;
                if (cycle (i, -1)) {
                    if (quant < k) printf ("N\n");
                    else printf ("Y\n");
                    break;                   
                }
            }
        }
        if (i == l) printf ("Y\n");
    }
}
