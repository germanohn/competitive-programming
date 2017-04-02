#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int M = 505;
const int inf = 1e6 + 5;

int r, c;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int d[M][M], t[M][M];

bool can(pii nx, int pt) {
    if (nx.ff < 0 || nx.ff >= r || nx.ss < 0 || nx.ss >= c || pt >= t[nx.ff][nx.ss])
        return false;
    return true;
}

void clear() {
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++)
            d[i][j] = inf;
}

bool bfs(int val) {
    clear();
    d[0][0] = val;
    queue<pii> q;
    q.push(pii(0, 0));
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nx;
            nx.ff = cur.ff + dx[i];
            nx.ss = cur.ss + dy[i];
            if (can(nx, d[cur.ff][cur.ss] + 1) && d[nx.ff][nx.ss] > d[cur.ff][cur.ss] + 1) {
                d[nx.ff][nx.ss] = d[cur.ff][cur.ss] + 1;
                q.push(nx);
            }
        }
    }
    if (d[r - 1][c - 1] != inf) return true;
    return false;
}

int main() {
    scanf(" %d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %d", &t[i][j]);
        }
    }

    int lo, hi;
    lo = 0, hi = t[0][0] - 1;
    while (lo != hi) {
        int mid = (lo + hi + 1) / 2;
        if (bfs(mid)) 
            lo = mid;
        else 
            hi = mid - 1;
    }   

    if (!bfs(lo)) 
        printf("-1\n");
    else 
        printf("%d\n", lo);
}
