#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#define MAX 1005
#define pb push_back

using namespace std;

vector<int> adj[MAX];

int n, d, a, b, soma, mini;
bool vis[MAX];

void dfs (int s) {
    stack<int> p;
    p.push (s);
    vis[s] = true;
    soma = 1;
    while (!p.empty ()) {
        int v = p.top ();
        p.pop ();
        for (int i = 0; i < adj[v].size (); i++) {
            if (vis[adj[v][i]] == false) {
                vis[adj[v][i]] = true;
                p.push (adj[v][i]);
                soma++;
            }
        }
    }
    if (soma < mini) mini = soma;
}

int main () {
    scanf ("%d %d", &n, &d);
    for (int i = 1; i <= d; i++) {
        scanf ("%d %d", &a, &b);
        adj[b].pb (a);
    }
    mini = INT_MAX;

    for (int i = 1; i <= n; i++)
        vis[i] = false;

    for (int i = 1; i <= n; i++)
        if (vis[i] == false)
            dfs (i);
    printf ("%d\n", mini);
}
