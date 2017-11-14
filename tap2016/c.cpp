#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e4 + 5;

int n, m;
int in[N], pre[N];
bool pass[N], reg[N];
vector<int> adj[N];

int dfs(int u) {
    int ans = 0;
    for (auto v : adj[u]) {
        if (reg[u]) pre[v]++;
        if (pre[v] == in[v] && pass[v]) {
            reg[v] = true;
            ans++;
            ans += dfs(v);
        }
    }

    return ans;
}

int main() {
    while (scanf(" %d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++)
            adj[i].clear(), in[i] = 0, pre[i] = 0, reg[i] = false, pass[i] = false;

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            a--, b--;
            adj[a].pb(b);
            in[b]++;
        }

        int regist = 0;
        for (int i = 0; i < n; i++) {
            int pi;
            scanf(" %d", &pi);
            pi--;
            pass[pi] = true;
            if (pre[pi] == in[pi]) reg[pi] = true;
            regist += reg[pi] + dfs(pi);
            printf("%d\n", regist);
        }
    }
}

