#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, turn;
int color[MAX];
int seen[MAX];
vector<int> adj[MAX];

int dfs(int u, int label) {
    seen[u] = turn;
    int ans = 1;
    for (int v : adj[u]) {
        if (seen[v] == turn) continue;
        if (label != -1) {
            if (color[v] != label) 
                ans = 0;
            else 
                ans *= dfs(v, label);
        } else {
            ans *= dfs(v, color[v]);
        }
    }
    return ans;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 0; i < n; i++) 
        scanf(" %d", &color[i]);
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            if (color[v] != color[i]) {
                turn++;
                if (dfs(v, -1)) {
                    printf("YES\n%d\n", v + 1);
                    return 0;
                } 
                turn++;
                if (dfs(i, -1)) {
                    printf("YES\n%d\n", i + 1);
                    return 0;
                } 
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n1\n");
}

