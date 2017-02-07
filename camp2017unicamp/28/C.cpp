#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 403;
const int A = 11234;
const int inf = 123456;
int a[N], q, n;
int adj[N][N];
vector<pii> par;
map<int, int> m;
int cs;

int main () {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);

    for(int i = 0; i < A; i++) {
        for(int j = 0; j < n; j++) {
            int tgt = 2*a[j] - i;
            par.pb(pii(i, tgt));
        }
    }

    for(int u = 0; u < N; u++)
        for(int v = 0; v < N; v++)
            adj[u][v] = u == v ? 0 : inf;

    for(pii p : par) {
        if(!m[p.first]) m[p.first] = ++cs; 
        if(!m[p.second]) m[p.second] = ++cs; 

        int u = m[p.first];
        int v = m[p.second];
        printf("%d %d\n", u, v);
        //adj[u][v] = 1;
    }

    for(int k = 1; k <= cs; k++) 
        for(int u = 1; u <= cs; u++)
            for(int v = 1; v <= cs; v++)
                adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);

    scanf("%d",&q);
    while(q--){
        int s, t;
        scanf("%d %d", &s, &t);
        if(!m[s] || !m[t]) puts("-1");
        else {
            int u = m[s];
            int v = m[t];
            if(adj[u][v] == inf) puts("-1");
            else printf("%d\n", adj[u][v]);
        }
    }
}

