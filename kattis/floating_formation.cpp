#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;
const int inf = 1e6 + 5;

int n, m, k;
int d[N], dg[N], fix[N], p[N];
vector<int> adj[N];

void bfs() {
    queue<int> q;
    for (int i = 0; i < n; i++) 
        d[i] = inf; 
    for (int i = 0; i < n; i++) {
        if (fix[i]) {
            q.push(i);
            d[i] = 0;
            p[i] = i;
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : adj[x]) {
            if (d[nx] > d[x] + 1) {
                p[nx] = x;
                d[nx] = d[x] + 1;
                q.push(nx);
            }
        }
    }
}

void set_fix(int u) {
    while (p[u] != u) {
        fix[u] = true;
        u = p[u];
    }
}

void topo_sort() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (dg[i] == 1) 
            q.push(i);
        fix[i] = true;
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        fix[x] = false;
        
        for (int nx : adj[x]) {
            dg[nx]--;
            if (dg[nx] == 1) 
                q.push(nx);
        }
    }
}

int main () {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d %d", &n, &m, &k);
        for (int i = 0; i < n; i++) { 
            adj[i].clear();
            dg[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            a--, b--;
            adj[a].pb(b);
            adj[b].pb(a);
            dg[a]++;
            dg[b]++;
        }

        topo_sort();

        while (k--) {
            bfs();

            int cur = -1, idx = -1;
            for (int i = 0; i < n; i++) {
                if (d[i] > cur) {
                    cur = d[i];
                    idx = i;
                }
            }

            set_fix(idx);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) 
            if (!fix[i])
                ans++;
        printf("%d\n", ans);
    }
}

