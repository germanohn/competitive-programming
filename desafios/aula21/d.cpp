#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 65;
const int inf = 1e9;

int n, m, r, s, t, k, opt;
int me[MAX][MAX][MAX], d[MAX][MAX][MAX], dis[MAX][MAX];

void floyd(int car) {

    for (int l = 0; l < n; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j][car] = min(d[i][j][car], d[i][l][car] + d[l][j][car]);
                dis[i][j] = min(dis[i][j], d[i][j][car]);
            }
        }
    }
}

int dp(int source, int dest, int ch) {
    if (source == dest) return 0;
    if (ch < 0) return inf;
    if (me[source][dest][ch] != -1) return me[source][dest][ch];
    
    int ans = inf;
    for (int i = 0; i < n; i++) {
        if (i == source) continue;
        ans = min(ans, dis[source][i] + dp(i, dest, ch - 1));
    }

    return me[source][dest][ch] = ans;
}

int main () {
    scanf(" %d %d %d", &n, &m, &r);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            dis[i][j] = inf;
    for (int l = 0; l < m; l++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                scanf(" %d", &d[i][j][l]);

    for (int i = 0; i < m; i++) 
        floyd(i);

    while (r--) {
        int ans = inf;
        scanf(" %d %d %d", &s, &t, &k);
        s--, t--;
        opt = min(60, k);
        ans = min(ans, dp(s, t, opt));
        printf("%d\n", ans);
    }
}

