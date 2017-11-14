#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int Z = 1005;
const double inf = 1e6 + 5;

int n, z;
int c[Z];
double d[N];
vector<pii> adj;

bool bellman(double x) {
    double aux[Z];
    for (int i = 0; i < z; i++) 
        aux[i] = double(c[i]) + x;
    for (int i = 1; i < n; i++)
        d[i] = inf;
    d[0] = 0.;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < z; j++) {
            int from = adj[j].ff;
            int to = adj[j].ss;
            if (d[from] + double(aux[j]) < d[to])
                d[to] = d[from] + double(aux[j]);
        }
    }

    for (int j = 0; j < z; j++) {
        int from = adj[j].ff;
        int to = adj[j].ss;
        if (d[from] + double(aux[j]) < d[to])
            return 0;
    }

    return 1;
}

int main () {
    scanf(" %d %d", &n, &z);
    for (int i = 0; i < z; i++) {
        int ai, bi;
        scanf(" %d %d %d", &ai, &bi, &c[i]);
        c[i] = -c[i];
        ai--, bi--;
        adj.pb(pii(ai, bi));
    }

    int cont = 0;
    double lo = 0., hi = inf;
    while (cont < 150) {
        double mid = (lo + hi) / 2.;
        if (bellman(mid))
            hi = mid;
        else 
            lo = mid;
        cont++;
    }

    printf("%.10lf\n", lo);
}

