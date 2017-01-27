#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 505;

int n, m, k, cont_free;
int dx[5] = {-1, 1, 0, 0};
int dy[5] = {0, 0, -1, 1};
bool seen[MAX][MAX];
char maze[MAX][MAX];

bool can(pii x) {
    if (x.ff >= 0 && x.ff < n && x.ss >= 0 && x.ss < m 
        && !seen[x.ff][x.ss] && maze[x.ff][x.ss] != '#') return true;
    return false;
}

void bfs(int a, int b) {
    queue<pii> q;
    q.push(pii(a, b));
    seen[a][b] = true;
    int cont_seen = 1;
    while (!q.empty() && cont_seen < cont_free - k) {
        pii x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nx = pii(x.ff + dx[i], x.ss + dy[i]);
            if (can(nx) && cont_seen < cont_free - k) {
                cont_seen++;
                seen[nx.ff][nx.ss] = true;
                q.push(nx);
            }
        }
    }
}

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == '.') 
                cont_free++;
        }
    }
    bool ok;
    if (k) ok = false;
    else ok = true;
    for (int i = 0; !ok && i < n; i++) {
        for (int j = 0; !ok && j < m; j++) {
            if (maze[i][j] == '.') {
                bfs(i, j);
                ok = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '#') printf("#");
            else if (seen[i][j] || !k) printf(".");
            else printf("X");
        }
        printf("\n");
    }
}

