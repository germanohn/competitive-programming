#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

const int MAX = 105;

int t, l, h, w, n, s;//h é o numero de linhas e w e o numero de colunas
int pto[MAX], quant;//quant e a quantidade de caras pra salvar
int fx[] = {-1, 1, 0, 0, 0, 0};
int fy[] = {0, 0, -1, 1, 0, 0};
int fz[] = {0, 0, 0, 0, -1, 1};
char A[105][105][15];
int d[105][105][15];
int me[MAX][10005];

struct tii {
    int x, y, z;
};

tii st, v[MAX];

void bfs () {
    queue<tii> q;
    q.push (st);
    d[st.x][st.y][st.z] = 0;
    while (!q.empty ()) {
        int x, y, z;
        x = q.front ().x, y = q.front ().y, z = q.front ().z;
        q.pop ();
        for (int i = 0; i < 6; i++) {
            if (x + fx[i] < h && x + fx[i] >= 0 &&
                y + fy[i] < w && y + fy[i] >= 0 && 
                z + fz[i] < l && z + fz[i] >= 0) {
                int atu = A[x][y][z];
                int nxt = A[x+fx[i]][y+fy[i]][z+fz[i]];
                if (fz[i] != 0) {
                    if (fz[i] < 0) { 
                        if (atu != 'D') continue;
                    }
                    else { 
                        if (atu != 'U') continue;
                    }
                }
                if (nxt == 'X') continue;
                int &dNxt = d[x+fx[i]][y+fy[i]][z+fz[i]];
                if (dNxt > d[x][y][z] + 1) {
                    dNxt = d[x][y][z] + 1;
                    tii nov;
                    nov.x = x+fx[i], nov.y = y+fy[i], nov.z = z+fz[i];
                    q.push (nov);
                } 
            }
        }
    }
}

int dp (int i, int tempo) {
    if (i == quant) return 0;
    int &m = me[i][tempo];
    if (m != -1) return m;
    int m1 = INT_MIN, m2 = INT_MIN; 
    if (tempo >= 3*d[v[i].x][v[i].y][v[i].z]) {
        m1 = pto[i] + dp (i+1, tempo - 3*d[v[i].x][v[i].y][v[i].z]);
    }
    m2 = dp (i+1, tempo);
    return m = max (m1, m2);
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d %d %d %d", &l, &h, &w, &n, &s);
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    scanf (" %c", &A[i][j][k]);
                    char at = A[i][j][k];
                    if (at == 'S') { 
                        st.x = i, st.y = j, st.z = k;             
                    }
                }
            }
        }
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < h; i++) {     
                for (int j = 0; j < w; j++) {
                    d[i][j][k] = INT_MAX;
                }
            }
        }
        int fl, row, col, ponto;
        quant = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d %d %d", &fl, &row, &col, &ponto);
            fl--, row--, col--;
            v[i].x = row, v[i].y = col, v[i].z = fl;
            pto[i] = ponto;
            quant = i;
        }
        quant++;
        bfs ();
        memset (me, -1, sizeof (me));
        printf ("%d\n", dp (0, s));  
        
    }
}

