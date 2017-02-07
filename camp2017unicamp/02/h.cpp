#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 205;

int n, m;
set<int> adj[MAX];
bitset<205> met[MAX];

void calc() {
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        met[i] = 0;
        for (auto v : adj[i]) { 
            met[i][v] = 1;
            met[i] |= met[v];
        }
        ans += met[i].count();
    }
    printf("%d\n", ans);
}

int main () {
    freopen("settling.in", "r", stdin);
    freopen("settling.out", "w", stdout);
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        if (a > b) swap(a, b);
        adj[a].insert(b);
    }
    calc();
    int k;
    scanf(" %d", &k);
    for (int i = 0; i < k; i++) {
        char c;
        int a, b;
        scanf(" %c %d %d", &c, &a, &b);
        if (c == '?') {
            if (met[a][b] != 0) printf("YES\n");
            else printf("NO\n");
        } else if (c == '+') {
            adj[a].insert(b);
            calc();
        } else {
            adj[a].erase(b);
            calc();
        }
    }
}

