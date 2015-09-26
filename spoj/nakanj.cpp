#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
int t, s, e, a, b;
int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
char ini, fim;
int m[10][10];

void bfs (int r, int c) {
    queue<pii> q;
    q.push (mp (r, c));
    while (!q.empty ()) {
        int x, y;
        x = q.front ().first;
        y = q.front ().second;
        q.pop ();
        for (int i = 0; i < 8; i++) {
            if (x + kx[i] >= 1 && x + kx[i] <= 8 && 
                y + ky[i] >= 1 && y + ky[i] <= 8) {
                if (m[x + kx[i]][y + ky[i]] > m[x][y] + 1) { 
                    m[x + kx[i]][y + ky[i]] = m[x][y] + 1;    
                    q.push (mp (x + kx[i], y + ky[i]));
                }
            }
        }
    }
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                m[i][j] = INT_MAX;
            }
        }
        
        scanf (" %c %d %c %d", &ini, &s, &fim, &e);
        a = ini - 'a' + 1;
        b = fim - 'a' + 1;
        m[a][s] = 0;
        bfs (s, a);
        printf ("%d\n", m[b][e]);
        /*for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                printf ("%d ", m[i][j]);
            }
            printf ("\n");
        }*/
    }
}
