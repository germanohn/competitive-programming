#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char g[N][N];

struct point {
    int x, y;

    point() {}
    point(int x, int y) : x(x), y(y) {}

    point operator+ (point a) {
        return point(x + a.x, y + a.y);
    }

    bool valid() {
        if (x >= 0 && x < n && y >= 0 && y < m && g[i][j] != '*')
            return true;
        return false;
    }
};

queue<point> q;

void bfs() {
    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            point nx = cur + point(dx[i], dy[i]);
            if (nx.valid()) {

            }
        }
    }
}

bool dfs(int u) {
    seen[u] = true;

    for (int v : adj[u]) {
        if (!seen[v]) {
            if (dfs(v))
                mark[v] = u;
        }
    }
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == 'S') {
                q.push(point(i, j));
            } 
        }
    }
}

