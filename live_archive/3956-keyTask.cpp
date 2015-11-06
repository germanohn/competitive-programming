#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int r, c, bit;
int A[MAX][MAX], d[MAX][MAX][40];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
pii st;

int chave (char a, char b) {
    char ch = A[a][b];
    if (ch == 'b') return 1;
    if (ch == 'y') return 2; 
    if (ch == 'r') return 4;
    if (ch == 'g') return 8;

}

void bfs () {
    queue<pii> q;
    q.push (mp (st.ff, st.ss));
    d[st.ff][st.ss][0] = 0;
    while (!q.empty ()) {
        int x, y;//posicao em A
        x = q.top ().ff;
        y = q.top ().ss;
        bit |= chave (x, y);//estado do bit nesse pos
        int dis = d[x][y][bit];
        for (int i = 0; i < 4; i++) {
            if (x + px[i] >= 0 && x + px[i] <= 0 &&
                y + py[i] >= 0 && y + py[i] <= 0) {
                char cel = A[x+px[i]][y+py[i]];
                if (cel != '#') {
                     
                }
            }
        }
    }
}

int main () {
    int ex = -1, ey = -1;
    while (scanf ("%d %d", &r, &c) && r != 0 && c != 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf ("%d", &A[i][j]);
                if (A[i][j] == '*') {
                    st.ff = i;
                    st.ss = j;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int l = 0; l < 40; l++) {
                    d[i][j][l] = INT_MAX;                                        
                }
            }
        }

    }
}
