#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[100005];
int n, k, m;
int door[100005];
bool f;

void bfs () {
    queue<pii> q;
    q.push (1);
    while (!q.empty ()) {
        int now = q.front ();
        q.pop ();
        for (int i = 0; i < adj[now].size (); i++) {
            int nx = adj[now][i];
            if (door[nx.ff] == chave[nx.ss]) {
                q.push (nx);
                if (nx.ff == n) {
                    f = true;
                    break;
                }
            }
        }
    }   
}

int main () {
    while (scanf ("%d %d %d", &n, &k, &m) && n != -1 && k != -1 && m != -1) {
        f = false;
        int ch, d;
        for (int i = 0; i <= n; i++)
            chave[i] = 0, door[i] = 0;
        for (int i = 0; i < k; i++) {
            scanf ("%d %d", &ch, &d); 
            chave[ch] = d;
            door[d] = ch;      
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b);
            adj[a].pb (b);
            adj[b].pb (a);
        }
        bfs ();
        if (f) printf ("Y\n");
        else printf ("N\n");
    }
}
