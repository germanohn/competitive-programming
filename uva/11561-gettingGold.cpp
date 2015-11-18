#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int N = 55;

char A[N][N]; 
int d[N][N], w, h, gold;
int gx[] = {1, -1, 0, 0};
int gy[] = {0, 0, 1, -1};
pii st;
queue<pii> q;

void bfs () {
    while (!q.empty ()) {
        int x = q.front ().ff, y = q.front ().ss;
        q.pop ();
        bool f = true;
        for (int i = 0; i < 4; i++) {
            int nx = x+gx[i], ny = y+gy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (A[nx][ny] == '#') continue;
                if (A[nx][ny] == 'T') {
                    f = false;
                }
            }
        }
        if (f) {
            for (int i = 0; i < 4; i++) {
                int nx = x+gx[i], ny = y+gy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (A[nx][ny] == '#') continue;
                    if (d[nx][ny] > d[x][y] + 1) {
                        d[nx][ny] = d[x][y] + 1;
                        if (A[nx][ny] == 'G') {
                            gold++;
                            A[nx][ny] = '.';
                        }
                        q.push (pii (nx, ny));
                    }
                }
            }  
        }
    }
            
}

int main () {
    while (scanf ("%d %d", &w, &h) != EOF) {
        gold = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf (" %c", &A[i][j]);
                d[i][j] = INT_MAX;
                if (A[i][j] == 'P') {
                    q.push (pii (i, j));
                    d[i][j] = 0;
                }
            }
        }
        bfs ();
        printf ("%d\n", gold);
    }
}
