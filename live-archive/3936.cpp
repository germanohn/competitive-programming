#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 50005;

int h, r, degree[MAX];
bool mark[MAX];
pii vp[MAX];
vector<int> adj[MAX];

int main () {
    while (scanf ("%d %d", &h, &r) && h != 0 && r != 0) {
        int u, v;
        for (int i = 0; i < h; i++) 
            adj[i].clear (), degree[i] = 0;
        for (int i = 0; i < r; i++) {
            scanf ("%d %d", &u, &v);
            u--, v--;
            adj[u].pb (v);
            adj[v].pb (u);
            degree[u]++;
            degree[v]++;
        }
        for (int i = 0; i < h; i++) {
            vp[i].ff = degree[i];
            vp[i].ss = i;
        }
        sort (vp, vp+h, greater<pii> ());
        /*for (int i = 0; i < h; i++) {
            printf ("%d ", vp[i].ss);
        }
        printf ("\n");
        */int i;
        bool f = true;
        for (int j = 0; j < h; j++) 
            mark[j] = false;
        mark[vp[0].ss] = true;
        int qClic = 1, qTmp = 0;
        for (i = 1; f && i < h; i++) {
            u = vp[i].ss;
            qTmp = 0;
            for (int j = 0; j < adj[u].size (); j++) 
                if (mark[adj[u][j]])
                    qTmp++;
            if (qTmp != qClic)
                f = false;
            if (f) qClic++, mark[u] = true;
        }
        f = true;
        for (int j = i; f && j < h; j++) {
            u = vp[j].ss;
            for (int k = 0; f && k < adj[u].size (); k++) 
                if (!mark[adj[u][k]])
                    f = false;
        }
        if (!f) printf ("N\n");
        else printf ("Y\n");
    }
}

