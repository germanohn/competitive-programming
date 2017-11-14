#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int Z = 1005;
const int inf = 1e6 + 5;

int n, z;
int c[Z];
double d[N][N];
vector<pii> adj;

int main () {
    scanf(" %d %d", &n, &z);
    for (int i = 0; i < z; i++) {
        int ai, bi;
        scanf(" %d %d %d", &ai, &bi, &c[i]);
        ai--, bi--;
        adj.pb(pii(ai, bi));
    }

    double ans = 0.;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            for (int step = 0; step < n; step++) 
                d[j][step] = -inf;
        d[i][0] = 0;

        for (int step = 1; step < n; step++) {
            for (int j = 0; j < z; j++) {
                int from = adj[j].ff;
                int to = adj[j].ss;
                if (d[from][step - 1] + double(c[j]) > d[to][step]) 
                    d[to][step] = d[from][step - 1] + double(c[j]);
            } 
        }

        for (int j = 1; j < n; j++) {
            if (d[i][j] / double(j) > ans)
                ans = d[i][j] / double(j);
        }
    }

    printf("%.10lf\n", ans);
}

