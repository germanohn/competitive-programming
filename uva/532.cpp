#include <bits/stdc++.h>

using namespace std;

int l, r, c;
int iniL, iniR, iniC;
int fimL, fimR, fimC;
int ll[3] = {-1, 0, 1}
int rr[4] = {-1, 0, 1, 0}
int cc[4] = {0, 1, 0, -1}
char m[32][32][32];

struct no{
    int i, j, k;
};

no pos;

int bfs () {
    queue<no> q;
    pos.i = iniL;
    pos.j = iniR;
    pos.k = iniC;
    q.push (pos);
    while (!q.empty ()) {
        int x = q.front ().i
        int y = q.front ().j
        int z = q.front ().z
        q.pop ();
        if (m[x][y][z] == 'e'
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 4; b++) {
                if (x + ll[a] >= 0 && x + ll[a] <= 2 &&
                    y + rr[b] >= 0 && y + rr[b] <= 3 &&
                    z + cc[b] >= 0 && z + cc[b] <= 3) {
                    if (m[x + ll[a]][y + rr[b]][z + cc[b]] != '#') 
                        m[x + ll[a]][y + rr[b]][z + cc[b]] = m[x][y][z] + 1;
                }    
                pos.i = x + ll[a];
                pos.j = y + rr[b];
                pos.k = z + cc[b];
                q.push (pos);
            }
        }
    }
}   

int main () {
    while (scanf ("%d %d %d", &l, &r, &c) && l != 0) {
        for (int i = 0; i < l; i++) 
            for (int j = 0; j < r; j++) 
                for (int k = 0; k < c; k++) {
                    scanf ("%c", &m[i][j][k]);
                    if (m[i][j][k] == S) {
                        iniL = i;
                        iniR = j;
                        iniC = k;
                        m[i][j][k] = 0;
                    }
                    else if (m[i][j][k] == E) {
                        fimL = i; 
                        fimR = j;
                        fimC = k;
                    }
                }
        if (bfs ())
            printf ("Escaped in %d minute(s).", cont);
        else
            printf ("Trapped!\n");
    }
}
