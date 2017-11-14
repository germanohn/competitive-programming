#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e3 + 5;
const int inf = 1e6;

int n, ans;
int in[N];
bool has[N];
vector<int> adj[N];

void toposort() {
    queue<int> q;
    for (int i = 0; i < n; i++) 
        if (!in[i]) q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (!has[u]) ans++;
        has[u] = true;

        int mini = inf, u_mini = -1;
        for (auto v : adj[u]) {
            if (has[v]) continue;
            if (in[v] < mini) {
                mini = in[v];
                u_mini = v;
            }
        }

        if (u_mini != -1) {
            has[u_mini] = true;
        }

        for (auto v : adj[u]) {
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf(" %d", &k);
        while (k--) {
            int a;
            scanf(" %d", &a);
            a--;
            adj[i].pb(a);
            in[a]++;
        }
    }

    toposort();

    printf("%d\n", ans);
}

