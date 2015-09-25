#include <bits/stdc++.h>

iiusing namespace std;

int l, r, c, cont, m[32][32][32];
int iniL, iniR, iniC;
int fimL, fimR, fimC;
int mx[6] = {0, 0, 0, 0, -1, 1};
int my[6] = {0, 0, -1, 1, 0, 0};
int mz[6] = {-1, 1, 0, 0, 0, 0};
char d;

struct no{
    int i, j, k;
};

no pos;

int bfs () {
    queue<no> q;
    pos.i = iniR;
    pos.j = iniC;
    pos.k = iniL;
    q.push (pos);
    while (!q.empty ()) {
        int x = q.front ().i;
        int y = q.front ().j;
        int z = q.front ().k;
        q.pop ();
        if (x == fimR && y == fimC && z == fimL) {
            cont = m[x][y][z];
            return 1;
        }
        for (int a = 0; a < 6; a++) {
                if (x + mx[a] >= 0 && x + mx[a] < r &&
                    y + my[a] >= 0 && y + my[a] < c &&
                    z + mz[a] >= 0 && z + mz[a] < l) {
                    int &kk = m[x + mx[a]][y + my[a]][z + mz[a]];
                    if (m[x][y][z] + 1 < kk) { 
                        kk = m[x][y][z] + 1;
                        pos.i = x + mx[a];
                        pos.j = y + my[a];
                        pos.k = z + mz[a];
                        q.push (pos);
                    }
                }    
        }
        
    }
    return 0;
}   

int main () {
    while (scanf ("%d %d %d", &l, &r, &c) && l != 0) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    scanf (" %c", &d);
                    if (d == 'S') {
                        iniL = i;
                        iniR = j;
                        iniC = k;
                        m[j][k][i] = 0;
                    }
                    else if (d == 'E') {
                        fimL = i; 
                        fimR = j;
                        fimC = k;
                        m[j][k][i] = INT_MAX;
                        
                    }
                    else if (d == '.')
                        m[j][k][i] = INT_MAX;
                    else if (d == '#')
                        m[j][k][i] = -1;                    
                }
            }
        }
        if (bfs ())
            printf ("Escaped in %d minute(s).\n", cont);
        else
            printf ("Trapped!\n");
    }
}
