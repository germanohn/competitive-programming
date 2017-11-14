#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

const int N = 1e4 + 5;
const int M = 1e6 + 5;

int n, m, k, q;
int junct[N], d[N], vis[N], ant[N], ori_ant[N];
int edge[M][2]; // 0: dis, 1: freq
vector<int> ori;
vector<int> adj[N];
map<int, int> mp;

int id(int a, int b) {
    if (a > b) swap(a, b);
    
    int cur = a * n + b;
    if (mp[cur] == 0) mp[cur] = q++;
    return mp[cur];
}

void dijkstra() {
    for (int i = 0; i < n; i++) 
        d[i] = N + 1;
    d[0] = 0;

    priority_queue<pii> pq;
    pq.push(pii(0, 0));
    while (!pq.empty()) {
        int cur = pq.top().ss;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = 1;

        for (auto nx : adj[cur]) {
            int e = id(cur, nx);
            int w = edge[e][0];
            if (d[nx] > d[cur] + w) {
                ant[nx] = cur;
                d[nx] = d[cur] + w; 
                pq.push(pii(-d[nx], nx));
            }
        }
    }
}

bool solve(int u) {
    while (u != 0) {
        for (auto v : adj[u]) {
            int e = id(u, v);
            if (v != u && edge[e][0] + d[v] == d[u] && v != ori_ant[u]) {
                return true;
            }
        }
        //printf("u %d nx %d\n", u, nx); 
        u = ant[u];
    }

    return false;
}

int main() {
    q = 1;
    scanf(" %d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int a;
        scanf(" %d", &a);
        a--;
        ori.pb(a);
        if (i >= 1) 
            ori_ant[a] = ori[i - 1];
        junct[a] = true;
    }

    for (int i = 0; i < m; i++) { 
        int ai, bi, ci; 
        scanf(" %d %d %d", &ai, &bi, &ci);
        ai--, bi--;

        adj[ai].pb(bi);
        adj[bi].pb(ai);

        int e = id(ai, bi);
        if (junct[ai] && junct[bi]) {
            if (ci == edge[e][0]) {
                edge[e][1]++;
            } else if (!edge[e][0] || ci < edge[e][0]) {
                edge[e][0] = ci;
                edge[e][1] = 1;
            }
        } else {
            if (!edge[e][0]) edge[e][0] = ci;
            else edge[e][0] = min(edge[e][0], ci);
            edge[e][1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            int e = id(i, j);
            if (junct[i] && junct[j] && edge[e][1] > 1) {
                printf("yes\n");
                return 0;
            }
        }
    }

    dijkstra();

    if (solve(n - 1)) printf("yes\n");
    else printf("no\n");
}

