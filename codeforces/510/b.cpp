#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 55;

// Identificando ciclos com Union Find
int n, m;
int p[MAX * MAX], sz[MAX * MAX];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
char t[MAX][MAX];

int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return true;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return false;
}

bool can(int i, int j, int d) {
    int x = i + dx[d], y = j + dy[d];
    if (x >= 0 && x < n && y >= 0 && y < m && t[x][y] == t[i][j]) return true;
    return false;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &t[i][j]);
            p[m * i + j] = m * i + j;
            sz[m * i + j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 2; d++) {
                int a = m * i + j, b = m * (i + dx[d]) + (j + dy[d]);
                if (can(i, j, d) && join(a, b)) {
                    printf("Yes\n");
                    return 0;
                }
            }    
        }
    }
    printf("No\n");
}

/* Com dfs
int n, m, turn;
int seen[MAX * MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char t[MAX][MAX];
vector<int> adj[MAX * MAX];

bool can(int i, int j, int d) {
    int x = i + dx[d], y = j + dy[d];
    if (x >= 0 && x < n && y >= 0 && y < m && t[x][y] == t[i][j]) return true;
    return false;
} 

bool dfs(int u, int p) {
    seen[u] = true;
    bool cycle = false;
    for (auto v : adj[u]) {
        if (v != p) {
            if (seen[v]) cycle = true;
            else cycle |= dfs(v, u);
        }
    }
    return cycle;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf(" %c", &t[i][j]);
    turn = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                int a = m * i + j, b = m * (i + dx[d]) + j + dy[d];
                if (can(i, j, d))
                    adj[a].pb(b);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!seen[m * i + j] && dfs(m * i + j, -1)) { 
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}

