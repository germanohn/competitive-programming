#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 50005;

int n, k, a, b, d[MAX], acc;
vector<pii> adj[MAX];

int mod (int n, int m) {
    if (n % m == 0) return m;
    return n % m;
}

void solve () {
    priority_queue<pii> p;
    p.push (mp (0, 1));
    d[1] = 0;
    while (!p.empty ()) {
        int x = p.top ().ss;
        p.pop ();
        for (int i = 0; i < adj[x].size (); i++) {
            pii next = adj[x][i];
            /* d[x]: distancia andada ate agora
            // primeiro next.ss: distancia que ele vai andar igual quando pegar elevador
            // 2*next.ss :e o total do circuito que o elevador faz
            // mod (d[x], 2*next.ss) : me dira onde que o elevador esta em seu trajeto, por
            // isso que se mod e zero tenho que retornar 2*next.ss para diminuir do 
            // 2*next.ss e (2*next.ss - mod) ser a posicao do elevador na sua trajetoria */
            int resto = mod (d[x], 2*next.ss);
            if (d[next.ff] > d[x] + next.ss + 2*next.ss - resto) {
                d[next.ff] = d[x] + next.ss + 2*next.ss - resto;
                p.push (mp (-d[next.ff], next.ff));
            }
        }
    }
}

int main () {
    scanf ("%d %d", &k, &n);
    for (int i = 0; i <= k; i++)
       d[i] = INT_MAX; 
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        adj[a].pb (mp (b, b-a));
        adj[b].pb (mp (a, b-a));
    }
    solve ();
    printf ("%d\n", 5*d[k]);
}
