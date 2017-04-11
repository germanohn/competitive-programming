#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 5;
const int inf = 1e6;

int n, k, d;
int p[N], dis[N];
bool seen[N];
vector<int> adj[N];
set<int> s, ans;
map<pii, int> road;

void bfs() {
    queue<pii> q;
    for (auto it = s.begin(); it != s.end(); it++) {
        q.push(pii(*it, -1));
        dis[*it] = 0;
    }
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        for (int nx : adj[x.ff]) {
            if (dis[x.ff] + 1 <= d && dis[nx] > dis[x.ff] + 1 && s.find(nx) == s.end()) {
                dis[nx] = dis[x.ff] + 1;
                q.push(pii(nx, x.ff));
            } else if (nx != x.ss && dis[nx] <= dis[x.ff] + 1) {
                int a = x.ff, b = nx;
                if (a > b) swap(a, b);
                ans.insert(road[pii(a, b)]);    
            }
        }
    }
}

int main () {
    scanf(" %d %d %d", &n, &k, &d);
    while (k--) {
        int a;
        scanf(" %d", &a);
        a--;
        s.insert(a);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        if (a > b) swap(a, b);
        road[pii(a, b)] = i + 1;
        adj[a].pb(b);
        adj[b].pb(a);
        dis[i] = inf;
    }
    dis[n - 1] = inf;

    bfs();
    printf("%d\n", ans.size());
    for (auto it = ans.begin(); it != ans.end(); it++) 
        printf("%d ", *it);
    printf("\n");
}

