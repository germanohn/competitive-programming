#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)

vector <int> v[200005];
int g[200005], cur[200005];
int main() {
        int c, p, x, l, y, z;
        scanf("%d %d %d %d", &c, &p, &x, &l);
        
        for (int i = 0; i < p; i++) {
                scanf("%d %d", &y, &z);
                v[y].pb(z);
                v[z].pb(y);
        }
        
        for (int i = 1; i <= c; i++) {
                g[i] = (int)v[i].size();
                cur[i] = g[i];
        }
        
        queue <int> q;
        q.push(l);
        
        while (!q.empty()) {
                int f = q.front();
                for (auto a : v[f]) {
                        if (!g[a]) continue;
                        cur[a]--;
                        if (cur[a] <= g[a]/2) {
                                g[a] = 0;
                                q.push(a);
                        }
                }
                g[f] = 0;
                q.pop();
        }

        if (g[x]) printf("stay\n");
        else printf("leave\n");
        return 0;
}
