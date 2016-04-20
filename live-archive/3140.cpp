#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 205;
const int inf = 1000000000;

int n, m;
int can[MAX][MAX], d[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char g[MAX][MAX];
queue<pii> q;

bool pode (int x, int y) {
    if ((x < 0 && x >= n) || (y < 0 && y >= m))
        return false;
    return true;
}

void bfs () {
    while (!q.empty ()) {
        pii u = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii v = pii (u.x + dx[i], u.y + dy[i]);
            if (pode (v.x, v.y) && can[v.x][v.y]) {
                if (d[v.x][v.y] == inf) {
                    d[v.x][v.y] = d[u.x][u.y] + 1;
                    q.push (v);
                }
            }
        }        
    }
}

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                can[i][j] = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf (" %c", &g[i][j]);
                if (g[i][j] == 'S') {
                    if (i == 0) {
                        q.push (pii (i, j));
                        if (j+1 < m) { 
                            q.push (pii (i, j+1));   
                            can[i][j+1] = true;
                            d[i][j+1] = 1;
                        }
                        d[i][j] = 1;
                    } else {
                        if (j+1 < m) {
                            can[i][j+1] = true;
                            d[i][j+1] = inf;
                        }
                        d[i][j] = inf;
                    }
                    can[i][j] = true;   
                } 
            }
        }
        bfs ();
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (can[n-1][j])
                ans = min (ans, d[n-1][j]);
        }
        printf ("%d\n", ans);
    }
}

