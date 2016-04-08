#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m, ans, a, b;
int degree[MAX];
vector<int> adj[MAX];
queue<int> q;

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        degree[b]++, degree[a]++;
        adj[a].pb (b);
        adj[b].pb (a);
    }
    for (int i = 1; i <= n; i++) { 
        if (degree[i] == 0)
            ans++;
        else if (degree[i] == 1)
            q.push (i);
    }
    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();
        if (degree[u] == 0)
           ans++; 
        for (int i = 0; i < adj[u].size (); i++) {
            int v = adj[u][i];
            degree[v]--;
            if (degree[v] == 1)
                q.push (v);
        }
    }
    printf ("%d\n", ans); 
}

