#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int banned;
int vis[N];
vector<int> adj[N];

void find_banned(int u) {
    vis[u]++;
    for (int v : adj[u]) {
        if (!vis[v]) {
            find_banned(v);
        } else if (vis[v] == 1) {
            banned = v;
        }
    }
    vis[u]++;
}

bool has_cycle(int u) {
    vis[u]++;
    bool has = false;
    for (int v : adj[u]) {
        if (v == banned)
            continue;
        if (!vis[v]) {
            has |= has_cycle(v);
        } else if (vis[v] == 1) {
            has = true;
        }
    }
    vis[u]++;
    return has;
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        u--, v--;
        adj[u].pb(v);
    }

    find_banned(0);
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }

    bool has = false;
    for (int i = 0; i < n; i++) {
        if (i != banned && !vis[i])
            has |= has_cycle(i);
    }

    if (!has) {
        printf("%d\n", banned + 1);
    } else {
        printf("-1\n");
    }
}

