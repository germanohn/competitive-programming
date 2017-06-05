#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 4e5 + 5;

int n, g;
bool appear;
map<pii, pii> adj;
map<pii, bool> seen;

void dfs(pii u) {
    seen[u] = true;
    if (u.ff == g || u.ss == g) 
        appear = true;
    if (!seen[adj[u]])
        dfs(adj[u]);
}

int main () {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &g);
        adj.clear();
        seen.clear();
        g--;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            scanf(" %d %d %d %d", &a, &b, &c, &d);
            a--, b--, c--, d--;
            adj[pii(a, i)] = pii(i, c);
            adj[pii(c, i)] = pii(i, a);
            adj[pii(b, i)] = pii(i, d);
            adj[pii(d, i)] = pii(i, b);
        }

        int ans = 0;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (!seen[it->ff]) {
                appear = false;
                dfs(it->ff);
                if (!appear)
                    ans++;
            }
        } 

        printf("%d\n", ans / 2);
    }
}

