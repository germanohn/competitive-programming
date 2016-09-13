#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 1000000000;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int grid[15][15], d[15][15];                
pii st;

bool can (pii x) {
    if (x.ff < 0 || x.ff >= n || x.ss < 0 || x.ss >= m || grid[x.ff][x.ss] == 2) return false;
    return true;
}

void bfs () {
    queue<pii> q;
    q.push (st);
    d[st.ff][st.ss] = 0;
    while (!q.empty ()) {
        pii x = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii nx = pii (x.ff + dx[i], x.ss + dy[i]);
            if (can (nx) && d[nx.ff][nx.ss] > d[x.ff][x.ss]+1) {
                d[nx.ff][nx.ss] = d[x.ff][x.ss]+1;
                q.push (nx);
            }
        }
    }
}

int main() {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf (" %d", &grid[i][j]);
            if (grid[i][j] == 3) {
                st.ff = i, st.ss = j;
            }
            d[i][j] = inf;
        }
    }
    bfs ();
    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) 
                ans = min (ans, d[i][j]);
        }
    }

    printf ("%d\n", ans);
}

