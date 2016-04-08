#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MAX 10000000000
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
ll d[205][205][5];
ll row[4] = {1, 0, -1, 0};
ll col[4] = {0, 1, 0, -1};
char room[205][205];

// direction do robo: south 0, left 1, north 2, right 3

struct tii {
    tii () {}
    tii (ll a, ll b, ll c) {
        x = a, y = b, dir = c;
    }
    ll x, y, dir;
};

bool pode (ll a, ll b) {
    if (a >= 0 && a < n && b >= 0 && b < n && room[a][b] != '#') return true;
    return false;
}

void bfs () {
    queue<tii> q;
    q.push (tii (0, 0, 0));
    while (!q.empty ()) {
        tii now = q.front ();
        q.pop ();
        ll cont = 0;
        for (ll i = now.dir; cont < 4; i++) {
            i %= 4;
            tii nx = (tii (now.x+row[i], now.y+col[i], 0));
            int dis;
            if (i == now.dir)
                dis = d[now.x][now.y][i];
            if (pode (nx.x, nx.y)) {
                ll cost = dis + 1 + cont;
                //printf ("de (%lld, %lld) para (%lld, %lld) cost %lld\n", now.x, now.y, nx.x, nx.y, cost);
                if (nx.x == n-1 && nx.y == n-1) 
                    cost += (i != 0) ? (4-i) : 0;
                //printf ("i %lld d[nx.x][nx.y][i] %lld\n\n", i, d[nx.x][nx.y][i]);
                if (d[nx.x][nx.y][i] > cost) {
                    d[nx.x][nx.y][i] = cost;
                    nx.dir = i;
                    q.push (tii (nx));
                }  
            }
            cont++;
        }
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf (" %c", &room[i][j]);
        }
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            for (int l = 0; l < 5; l++)
                d[i][j][l] = MAX;
    d[0][0][0] = d[0][0][1] = d[0][0][2] = d[0][0][3] = 0;
    bfs ();
    ll ans = MAX;
    for (int i = 0; i < 4; i++) 
        ans = min (ans, d[n-1][n-1][i]);
    cout << ans << endl;
}

