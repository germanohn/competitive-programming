#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 100005;

int n, m, ans, leaves;
int cat[MAX];
vector<int> adj[MAX];

void dfs (int u, int p, int cats, int tmp) {
    if (!cat[u]) tmp = 0;
    else tmp++;
    cats = max (cats, tmp);
    if (adj[u].size () == 1 && u != 1) {
        leaves++;
        if (cats > m) ans++;
    }
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        if (v != p) 
            dfs (v, u, cats, tmp);
    }
}

int main() {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf (" %d", &a);
        if (a) cat[i+1] = 1;
        else cat[i+1] = 0; 
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf (" %d %d", &u, &v);
        adj[u].pb (v);
        adj[v].pb (u);
    }
    
    dfs (1, 0, 0, 0);
    ans = leaves-ans;
    printf ("%d\n", ans);
}

