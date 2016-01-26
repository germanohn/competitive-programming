#include <bits/stdc++.h>
#define MAX 1005
#define ff first
#define ss second 
using namespace std;
typedef pair<int, int> pii;

char maze[MAX][MAX];
int d[MAX][MAX];
int r, c;
queue<pii> q;

bool pode (int x, int y) {
    if (x >= 0 && x < r && y >= 0 && y < c && maze[x][y] != '#') return true;
    return false;
}

bool end (int x, int y) {
    if (x == 0 || x == r-1 || y == 0 || y == c-1) return true;
    return false;
}

void bfs () {
    while (!q.empty ()) {
        pii n = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii p.ff = n.ff+x[i], p.ss = n.ss+y[i];
            if (pode (p.ff, p.ss) && d[p.ff][p.ss] == INT_MAX) {
                
            }
        }
    }
}

int main () {
    scanf ("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf (" %c", &maze[i][j]);
            if (maze[i][j] == 'F') q.push (mp (i, j));
            if (end (i, j) && maze[i][j] == '.') d[i][j] = 0;
            d[i][j] = INT_MAX; 
        }
    }
    bfs ();
    
}
