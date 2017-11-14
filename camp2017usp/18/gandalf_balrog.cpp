#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int t, n, m;
vector<int> adj[N];

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < n; i++) 
            adj[i].clear();

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            a--, b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        bool f = false;
        for (int i = n - 1; !f && i >= 0; i--) {
            int great = 0;
            bool ok = true;
            for (int j = 0; ok && j < adj[i].size(); j++) {
                if (adj[i][j] > i)
                    great++;
                else if (adj[i][j] < i) 
                    ok = false;
            }

            if (great == (n - 1 - i) && ok) {
                printf("2 %d\n", i + 1);
                f = true;
            }
        }

        if (!f) printf("1\n");
    }
}

