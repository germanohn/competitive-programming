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

void solve () {
    priority_queue<pii> p;
    p.push (mp (0, 1));
    d[1] = 0;
    while (!p.empty ()) {
        int x = p.top ().ss;
        p.pop ();
        
        for (int i = 0; i < adj[x].size (); i++) {
            pii next = adj[x][i];
            int peso = 0;
            printf ("divisao %d\n", (d[x]/next.ss)%2);
            if (d[x] % next.ss == 0 && ((d[x]/next.ss) % 2) == 0) {
                printf ("prime\n");
                peso = 0;
            }
            else if (d[x] % next.ss == 0 && (d[x]/next.ss % 2) != 0) {
                printf ("segun\n");
                peso = next.ss;
            }
            else {
                printf ("tercei\n");
                peso = next.ss + next.ss - (d[x]%next.ss);
            }
            printf ("d[x] %d next.ss %d next.ff %d peso %d\n", d[x], next.ss, next.ff, peso);           
            if (d[next.ff] > d[x] + next.ss + peso) {
                printf ("\n");
                d[next.ff] = d[x] + next.ss + peso;
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
    printf ("oi\n");
    solve ();
    printf ("%d\n", 5*d[k]);
}
