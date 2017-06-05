#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 505;

int n, m, r1, c1, r2, c2;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char t[N][N];

bool can(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && t[x][y] == '.')
        return true;
    return false;
}

bool bfs() {
    queue<pii> q;
    q.push(pii(r1, c1));
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nx = pii(cur.ff + dx[i], cur.ss + dy[i]);
            //printf("cur (%d, %d) nx (%d, %d) r (%d, %d)\n", cur.ff, cur.ss, nx.ff, nx.ss, r2, c2);
            if (t[nx.ff][nx.ss] == 'X' && nx.ff == r2 && nx.ss == c2)
                return true;
            if (can(nx.ff, nx.ss)) {
                t[nx.ff][nx.ss] = 'X';
                q.push(nx);
            }
        }
    }
    return false;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &t[i][j]);
        }
    }

    scanf(" %d %d %d %d", &r1, &c1, &r2, &c2);
    r1--, c1--, r2--, c2--;
    //printf("to (%d, %d\n", r2, c2);
    if (bfs()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

