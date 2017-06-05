#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, k;
vector<int> d[N], adj[N];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        d[a].pb(i);
    }

    if (d[0].size() > 1) {
        printf("-1\n");
        return 0;
    }

    int sz = 0;
    for (int i = 1; i < n; i++) {
        int q = 0;
        for (int j = 0; q < d[i].size(); q++, j = (j + 1) % d[i - 1].size()) {
            if (d[i - 1].size() == 0) {
                printf("-1\n");
                return 0;
            }
            sz++;
            int v = d[i - 1][j];
            adj[v].pb(d[i][q]);
            adj[d[i][q]].pb(v);
        }
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].size() > k) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", sz);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            if (i < v) 
                printf("%d %d\n", i + 1, v + 1);
        }
    }
}

