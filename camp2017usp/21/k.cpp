#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2005;

int t;
int n;
vector<int> adj[N];
set<int> s;
set<pii> ans;

int main () {
    scanf(" %d", &t);
    while (t--) {
        s.clear();
        ans.clear();
        scanf(" %d", &n);
        for (int i = 0; i < n; i++)
            adj[i].clear();
        for (int i = 0; i < n; i++) {
            int a;
            scanf(" %d", &a);
            for (int j = 1; j < n; j++) {
                scanf(" %d", &a);
                a--;
                adj[i].pb(a);
            }
        }

        int root = 0;
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (adj[i][j] == root) continue;
                if (s.find(adj[i][j]) == s.end()) {
                    int cur = adj[i][j];
                    for (int k = 0; k < n - 1; k++) {
                        if (s.find(adj[cur][k]) == s.end()) {
                            int a = cur + 1, b = adj[cur][k] + 1;
                            if (a > b) swap(a, b);
                            ans.insert(pii(a, b));
                            break;
                        }
                    }

                    s.insert(adj[i][j]);
                }
            }
            //printf("size %d\n", ans.size());
        }

        for (auto v : ans) 
            printf("%d %d\n", v.ff, v.ss);
        printf("\n");
    }
}

