#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 25;
const int M = (1 << 20) + 5;
const int MOD = 1e9 + 7;

int n, m;
int me[N][M];
vector<int> adj[N];

int dp(int i, int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (me[i][mask] != -1) 
        return me[i][mask];

    int ans = 0;
    for (int j = 0; j < adj[i].size(); j++) {
        int v = adj[i][j];
       // printf("i %d v %d mask %d 1<<v %d %d\n", i, v, mask, 1 << v, (1 << v) & mask);
        if (((1 << v) & mask) == 0) { 
            ans = (ans + 1 + dp(v, mask | (1 << v)));
        }
    }

    return me[i][mask] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp(i, (1 << i)));
        //printf("%d\n\n", ans);
    }

    printf("%d\n", ans);
}

