#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 105;

int n, turn, ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dis[MAX][MAX], vis[MAX][MAX];
char A[MAX][MAX];

bool can (int x, int y, int mask) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        char c = A[x][y];
        int pos = tolower (c) - 'a';
        if (A[x][y] >= 'A' && A[x][y] <= 'J') {
            if (mask & (1 << pos))
                return true;
            return false;
        } else {
            if ((mask & (1 << pos)) == 0) 
                return true;
            return false;
        }
    }
    return false;
}

void bfs (int mask) {
    queue<pii> q;
    if (!can (0, 0, mask))
        return;
    q.push (pii (0, 0));
    dis[0][0] = 1;
    while (!q.empty ()) {
        pii x = q.front ();
        q.pop ();
        vis[x.ff][x.ss] = turn;
        if (x.ff == n-1 && x.ss == n-1)
            return;
        for (int i = 0; i < 4; i++) {
            pii nx = pii (x.ff + dx[i], x.ss + dy[i]);
            if (can (nx.ff, nx.ss, mask) && vis[nx.ff][nx.ss] != turn) {
                dis[nx.ff][nx.ss] = dis[x.ff][x.ss] + 1;
                q.push (nx);
            }
        }
    }
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        turn = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf (" %c", &A[i][j]);
                dis[i][j] = INT_MAX;
                vis[i][j] = 0;
            }
        }
        ans = INT_MAX;
        for (int i = 0; i < (1 << 10); i++) {
            turn++;
            bfs (i);
            ans = min (ans, dis[n-1][n-1]); 
        }
        if (ans == INT_MAX)
            printf ("-1\n");
        else 
            printf ("%d\n", ans); 
    }
}

