#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

const int N = 1e4 + 5;
const int inf = 1e8;

int n, m;
int d[N][2];
bool seen[N][2];
vector<pii> adj[N];
priority_queue<ppii> pq;

void dijkstra() {
    for (int i = 1; i <= n; i++) 
        d[i][0] = d[i][1] = inf;
    d[1][0] = 0;

    pq.push(ppii(0, pii(1, 0)));
    while (!pq.empty()) {
        ppii cur = pq.top();
        int l = cur.ff;
        int no = cur.ss.ff;
        int p = cur.ss.ss;
        pq.pop();

        if (seen[no][p])
            continue;
        seen[no][p] = true;

        for (pii nx : adj[no]) {
            if (d[nx.ff][!p] > d[no][p] + nx.ss) {
                d[nx.ff][!p] = d[no][p] + nx.ss;
                pq.push(ppii(-d[nx.ff][!p], pii(nx.ff, !p))); 
            }
        }
    }
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        scanf(" %d %d %d", &a, &b, &l);
        adj[a].pb(pii(b, l));
        adj[b].pb(pii(a, l));
    }

    dijkstra();

    if (d[n][0] != inf) {
        printf("%d\n", d[n][0]);
    } else {
        printf("-1\n");
    }
}

