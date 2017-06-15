#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2005;

int n, m;
char g[N][N], ans[N][N];
int dg[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char c_cur[4] = {'<', '>', '^', 'v'};
char c_nx[4] = {'>', '<', 'v', '^'};

struct cell {
    int x, y;

    cell() {}
    cell(int x, int y) : x(x), y(y) {}

    cell operator+ (cell a) {
        return cell(x + a.x, y + a.y);
    }

    bool valid() {
        if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.')
            return true;
        return false;
    }
};

queue<cell> q;

void bfs() {
    while (!q.empty()) {
        cell cur = q.front();
        q.pop();
        if (!dg[cur.x][cur.y]) continue;

        for (int i = 0; i < 4; i++) {
            cell nx = cur + cell(dx[i], dy[i]);

            if (nx.valid() && dg[nx.x][nx.y] > 0) {

                ans[cur.x][cur.y] = c_cur[i];
                ans[nx.x][nx.y] = c_nx[i];

                dg[cur.x][cur.y] = 0;
                dg[nx.x][nx.y] = 0;

                for (int j = 0; j < 4; j++) {
                    cell adj = nx + cell(dx[j], dy[j]);
                    if (adj.valid() && dg[adj.x][adj.y] > 1) {
                        dg[adj.x][adj.y]--;
                        if (dg[adj.x][adj.y] == 1)
                            q.push(adj);
                    }
                }
                break;
            }
        }
    }
}

int main () {
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &g[i][j]);
            ans[i][j] = g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    if (cell(i + dx[k], j + dy[k]).valid())
                        dg[i][j]++;
                }
                if (dg[i][j] == 1) 
                    q.push(cell(i, j));
                if (!dg[i][j]) {
                    printf("Not unique\n");
                    return 0;
                }
            }
        }
    }

    bfs();

    bool ok = true;
    for (int i = 0; ok && i < n; i++) {
        for (int j = 0; ok && j < m; j++) {
            if (dg[i][j])
                ok = false;
        }
    }

    if (ok) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Not unique\n");
    }
}

