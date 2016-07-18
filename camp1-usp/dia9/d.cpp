#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int inf = 1e6;

struct tuple {
    int w_r, w_c, b_r, b_c;
    tuple (int a, int b, int c, int d) {
        w_r = a, w_c = b, b_r = c, b_c = d;
    }
};

int dis[8][8][8][8];
int dr[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
int dc[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
pii w, b, w_d, b_d;

bool can (int w_r, int w_c, int b_r, int b_c) {
    if (w_r < 0 || w_r >= 8 || b_r < 0 || b_c >= 8) return false;
    if (w_r == b_r && w_c == b_c) return false;
    return true;
}

void bfs () {
    queue<tuple> q;
    q.push (tuple (w.ff, w.ss, b.ff, b.ss));
    dis[w.ff][w.ss][b.ff][b.ss] = 0;
    while (!q.empty ()) {
        tuple x = q.front ();
        q.pop ();
        // mexe so o primeiro cavalo
        for (int i = 0; i < 8; i++) {
            tuple nx = tuple (x.w_r + dr[i], x.w_c + dc[i], x.b_r, x.b_c);
            if (can (nx.w_r, nx.w_c, nx.b_r, nx.b_c) && dis[nx.w_r][nx.w_c][nx.b_r][nx.b_c] > dis[x.w_r][x.w_c][x.b_r][x.b_c] + 1) {
                 dis[nx.w_r][nx.w_c][nx.b_r][nx.b_c] > dis[x.w_r][x.w_c][x.b_r][x.b_c] + 1;
                 q.push (nx);
            }
        }
        // mexe so o segundo cavalo
        for (int i = 0; i < 8; i++) {
            tuple nx = (x.w_r, x.w_c, x.b_r + dr[i], x.b_c + dc[i]);
            if (can (nx.w_r, nx.w_c, nx.b_r, nx.b_c) && dis[nx.w_r][nx.w_c][nx.b_r][nx.b_c] > dis[x.w_r][x.w_c][x.b_r][x.b_c] + 1) {
                 dis[nx.w_r][nx.w_c][nx.b_r][nx.b_c] > dis[x.w_r][x.w_c][x.b_r][x.b_c] + 1;
                 q.push (nx);
            }
        }
    }
}

int main () {
    scanf (" %c%d %c%d %c%d %c%d", &w.ff, &w.ss, &b.ff, &b.ss, &w_d.ff, &w_d.ss, &b_d.ff, &b_d.ss);
    w.ff -= 'a', w.ss -= 1, w_d.ff -= 'a', w_d.ss -= 1;
    b.ff -= 'a', b.ss -= 1, b_d.ff -= 'a', b_d.ss -= 1;
    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < 8; j++) 
            for (int k = 0; k < 8; k++) 
                for (int l = 0; l < 8; l++)
                    dis[i][j][k][l] = inf;
    bfs ();
    printf ("dis %d\n", dis[w_d.ff][w_d.ss][b_d.ff][b_d.ss]);

}

