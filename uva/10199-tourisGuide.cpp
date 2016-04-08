#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, r, tempo, raiz;
int d[MAX], low[MAX], cut[MAX];
char a[35], b[35], num[MAX][35];
bool seen[MAX];
vector<int> adj[MAX];
map<string, int> city;
set<string> cam;

void dfs (int u, int p) {
    int nf = 0;
    seen[u] = true;
    d[u] = low[u] = tempo++;
    bool any = false;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            nf++;
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v] >= d[u])
                any = true;
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
    if (u == raiz && nf >= 2)
        cut[u] = true;
    if (u != raiz && any)  
        cut[u] = true;
}

int main () {
    string s1, s2;
    int test = 1;
    bool f = false;
    while (scanf ("%d", &n) && n != 0) {
        if (f) printf ("\n");
        f = true;
        tempo = 0;
        cam.clear (), city.clear ();
        for (int i = 0; i <= n; i++) 
            adj[i].clear (), seen[i] = false, cut[i] = false;
        int k = 1;
        string s;
        for (int i = 0; i < n; i++) { 
            scanf (" %s", a);
            s = a;
            city[s] = k;
            strcpy (num[k], s.c_str ());
            k++;
        }
        scanf ("%d", &r);
        for (int i = 0; i < r; i++) {
            scanf (" %s %s", a, b);
            s1 = a, s2 = b;
            adj[city[s1]].pb (city[s2]);
            adj[city[s2]].pb (city[s1]);
        }
        for (int i = 1; i < k; i++) {
            raiz = i;
            dfs (i, -1);
        }
        for (int i = 1; i < k; i++) 
            if (cut[i]) 
                cam.insert (num[i]);    
        int found = cam.size ();
        printf ("City map #%d: %d camera(s) found\n", test++, found);
        set<string>::iterator it;
        for (it = cam.begin (); it != cam.end (); it++) 
            cout << (*it) << '\n';
    }
}

