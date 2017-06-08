#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2005;

int n;
int d[MAX];
vector<int> adj[MAX];
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nx : adj[cur]) 
            if (d[nx] == MAX) {
                d[nx] = d[cur] + 1;
                q.push(nx);
            }
    }
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int p;
        scanf(" %d", &p);
        if (p == -1) {
            d[i] = 1;
            q.push(i);
        } else {
            d[i] = MAX;
            adj[p - 1].pb(i);
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, d[i]);
    printf("%d\n", ans);
}

