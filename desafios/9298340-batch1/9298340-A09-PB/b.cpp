#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

/////////////////0123456789
const int MAX = 35;

struct tii {
    tii () {}
    tii (int li, int ro, int co) {
        line = li, row = ro, col = co;
    }
    int line, row, col;
};

int linha, r, c;
int dLine[6] = {0, 0, 0, 0, -1, 1};
int dRow[6] = {-1, 1, 0, 0, 0, 0};
int dCol[6] = {0, 0, -1, 1, 0, 0};
int d[MAX][MAX][MAX];
char grid[MAX][MAX][MAX];
tii st, ed;

bool can (tii x) {
    if (x.line < 0 || x.line >= linha || x.row < 0 || x.row >= r 
        || x.col < 0 || x.col >= c) return false;
    if (grid[x.line][x.row][x.col] == '#') return false; 
    return true;
}

void bfs () {
    queue<tii> q;
    q.push (st);
    d[st.line][st.row][st.col] = 0;
    while (!q.empty ()) {
        tii x = q.front ();
        q.pop ();
        for (int i = 0; i < 6; i++) {
            tii nx = tii (x.line+dLine[i], x.row+dRow[i], x.col+dCol[i]);
            if (can (nx) && d[nx.line][nx.row][nx.col] > d[x.line][x.row][x.col]+1) {
                d[nx.line][nx.row][nx.col] = d[x.line][x.row][x.col]+1;
                q.push (nx);
            }
        }
    }
}

int main() {
    while (scanf (" %d %d %d", &linha, &r, &c)) {
        if (linha == 0 && r == 0 && c == 0) break;
        for (int l = 0; l < linha; l++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    char cel;
                    scanf (" %c", &cel);
                    grid[l][i][j] = cel;
                    if (cel == 'S') st.line = l, st.row = i, st.col = j;
                    else if (cel == 'E') ed.line = l, ed.row = i, ed.col = j;
                    d[l][i][j] = INT_MAX;
                }
            }
        } 
        bfs ();
        if (d[ed.line][ed.row][ed.col] != INT_MAX) printf ("Escaped in %d minute(s).\n", d[ed.line][ed.row][ed.col]);
        else printf ("Trapped!\n");
    }
}

