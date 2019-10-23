#include<bits/stdc++.h>
using namespace std;
            
typedef pair<int, int> pii;

const int N = 3e5 + 5;

set<int> ind_set;
vector<int> matching, adj[N];
vector<pii> edges;

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n, m;
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf(" %d %d", &u, &v);
            edges.push_back(pii(u, v));
            adj[u].push_back(i);
            adj[v].push_back(i);
        }

        ind_set.insert(1);
        for (int i = 2; ind_set.size() < n and matching.size() < n and i <= 3 * n; i++) {
            bool ok = true;
            for (int j = 0; ok and j < adj[i].size(); j++) {
                int id_e = adj[i][j];
                pii cur_e = edges[id_e];
                int cur_v = (cur_e.first != i) ? cur_e.first : cur_e.second;
                if (ind_set.find(cur_v) != ind_set.end()) {
                    ok = false;
                    ind_set.erase(cur_v);
                    matching.push_back(id_e);
                }
            }
            if (ok) {
                ind_set.insert(i);
            }
        }

        if (ind_set.size() == n) {
            printf("IndSet\n");
            for (auto it = ind_set.begin(); it != ind_set.end(); it++) {
                printf("%d ", *it);
            }
            printf("\n");
        } else {
            // matching of size 2 * n
            printf("Matching\n");
            for (int id_e : matching) {
                printf("%d ", id_e + 1);
            }
            printf("\n");
        }

        ind_set.clear();
        matching.clear();
        edges.clear();
        for (int i = 1; i <= 3 * n; i++) {
            adj[i].clear();
        }
    }
}

