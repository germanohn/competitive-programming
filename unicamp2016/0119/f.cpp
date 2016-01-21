#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

struct node {
    int des, d, v;
    double id;
};

vector<node> adj[205];

double me[205][1005];

double dp (int i, int p) {
    if (p == 0 && i == 1) return 0;
    if (p < 0) return ((double) INT_MIN);
    if (me[i][p] != 0) return me[i][p];
    double tmp = ((double) INT_MIN); 
    for (int j = 0; j < adj[i].size (); j++) {
        tmp = max (tmp, max (adj[i][j].id + dp (i, p-1), adj[i][j].v + dp (adj[i][j].des, p-adj[i][j].d))); 
    }
    return me[i][p] = tmp;
}

int main () {
    int n, m, p;
    scanf ("%d %d %d", &n, &m, &p);
    memset (me, 0, sizeof me);
    int ori, des, d, v;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d %d %d", &ori, &des, &d, &v);
        node a;
        a.des = des, a.d = d, a.id = ((double) v)/d, a.v = v;
        adj[ori].pb (a);
        a.des = ori;
        adj[des].pb (a);
    }
    printf ("%lf\n", dp (1, p));
}
