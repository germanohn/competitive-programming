#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first 
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005, N = 1005;

int n, m, k, x, y, quant;
int rta[N][N], d[N][N];
int rw[] = {0, 0, -1, 1};
int cl[] = {1, -1, 0, 0};
char A[N][N];
vector<pii> adj[MAX], vp;
queue<pii> q;
set<pii> s;

bool go (int a, int b) {
    if (a >= 0 && a < n && b >= 0 && b < m) return true;
    else return false;    
}

void bfs (int a, int b) {
    while (!q.empty ()) {
        int a = q.front ().ff, b = q.front ().ss;
        q.pop ();
        for (int i = 0; i < 4; i++) {
            if (go (a+rw[i], b+cl[i])) {
                if (A[a+rw[i]][b+cl[i]] == '*') {
                    quant++;
                    continue;
                }
                vp.pb (mp (a+rw[i], b+cl[i]));
                if (d[a+rw[i]][b+cl[i]] > d[a][b] + 1) {
                    d[a+rw[i]][b+cl[i]] = d[a][b] + 1;
                    q.push (mp (a+rw[i], b+cl[i]));
                }        
            }
        }
    }
}

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf (" %c", &A[i][j]);
            d[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.' && rta[i][j] == 0) {
                quant = 0;
                q.push (mp (i, j));
                d[i][j] = 0;
                bfs (i, j);
                rta[i][j] = quant;
                for (int l = 0; l < vp.size (); l++) {
                    rta[vp[l].ff][vp[l].ss] = quant;
                }
                vp.clear ();
            }
        }
    }
    int a, b;
    for (int i = 0; i < k; i++) {
        scanf ("%d %d", &a, &b);
        a--, b--;
        printf ("%d\n", rta[a][b]);
    }
}
