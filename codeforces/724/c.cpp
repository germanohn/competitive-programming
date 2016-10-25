#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;

/* direcoes: 0: direita superior, 1: direita inferior,
 *           2: esquerda superior, 3: esquerda inferior */

struct reta {
    pii c1, c2;
}

int n, m, k;
map<reta, set<pii> > diag;

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    
    for (int i = 0; i < k; i++) {
        int x, y, val;
        reta r;
        scanf ("%d %d", &x, &y);

        val = min (x, y);
        r.c1 = pii (x - val, y - val);

        val = min (n - x, m - y);
        r.c2 = pii (x + val, y + val);
        diag[r].insert (pii (x, y));

        val = min (x, m - y);
        r.c1 = pii (x - val, y + val);

        val = min (n - x, y);
        r.c2 = pii (x + val, y - val);
        diag[r].insert (pii (x, y));
    }

    pii at, nx;
    int tempo = 0, dir = 0;
    at = pii (0, 0);
    while (1) {
        if (dir == 0) {
            int val = min (n - at.x, m - at.y);
            nx = pii (at.x + val, at.y + val);

            if (nx.x == n && nx.y != m) {
                dir = 2;
            } else if (nx.x != n && nx.y == m) {
                dir = 1;
            } 

            reta r = pii (at, nx);
            for (auto it = diag[r].begin (); it != diag[r].end (); it++) {
                
            }
        } else if (dir == 1) {

        } else if (dir == 2) {

        } else {

        }
    }
}

