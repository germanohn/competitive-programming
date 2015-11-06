#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int r, c, dist;
int A[MAX][MAX], d[MAX][MAX][40];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
int flag;
vector<pii> ex;
pii st;

struct tii {
    int i, j, ch;
};

int chave (char ch) {
    if (ch == 'b') return 0;
    if (ch == 'y') return 1; 
    if (ch == 'r') return 2;
    if (ch == 'g') return 3;
    return -1;
}

int pode (int num, char cel) {
    if (cel == '.' || cel == 'X' || cel == '*' || (cel >= 'b' && cel <= 'y')) {
        return 1;
    }
    if (cel >= 'B' && cel <= 'Y') {
        num = num & (1 << chave (tolower (cel)));
        if (num) {
            return 1;            
        }
    }
    return 0;
}

int f (int a) {
    if (a == -1) return 0;
    return (1 << a);
}

int bfs () {
    queue<tii> q;
    tii p;
    p.i = st.ff, p.j = st.ss, p.ch = 0;
    q.push (p);
    d[st.ff][st.ss][0] = 0;
    while (!q.empty ()) {
        int x, y;//posicao em A
        int bit;
        x = q.front ().i;
        y = q.front ().j;
        bit = q.front ().ch;
        q.pop (); 
        if (A[x][y] == 'X') {
            dist = d[x][y][bit];   
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            if (x + px[i] >= 0 && x + px[i] < r &&
                y + py[i] >= 0 && y + py[i] < c) {
                char cel = A[x+px[i]][y+py[i]];
                if (cel != '#') {
                    int prox = bit;
                    prox |= f (chave (A[x+px[i]][y+py[i]]));
                    if (d[x+px[i]][y+py[i]][prox] > d[x][y][bit] + 1 && pode (prox, cel)) {
                        d[x+px[i]][y+py[i]][prox] = d[x][y][bit] + 1;
                        p.i = x+px[i], p.j = y+py[i], p.ch = prox;
                        q.push (p);
                    }                     
                }
                
            }
        }   
    }
}

int main () {
    while (scanf ("%d %d", &r, &c) && r != 0 && c != 0) {
        dist = 0;
        ex.clear ();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf (" %c", &A[i][j]);
                if (A[i][j] == '*') {
                    st.ff = i;
                    st.ss = j;
                }
                else if (A[i][j] == 'X')
                    ex.pb (mp (i, j));
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int l = 0; l < 40; l++) {
                    d[i][j][l] = INT_MAX;                                        
                }
            }
        }
        bfs ();

        if (dist > 0) printf ("Escape possible in %d steps.\n", dist);
        else printf ("The poor student is trapped!\n"); 
    }
}
