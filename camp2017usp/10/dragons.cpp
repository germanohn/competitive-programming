#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 305;

int n, f, d;
int sx[N], gx[N];
bool seen[N];
vector<int> cur;
vector<int> adj[N], ix[N];

bool cmp(int a, int b) {
    return gx[a] > gx[b];
}

void dfs(int u) {
    seen[u] = true; 
    for (int i = 0; i < ix[u].size(); i++)
        cur.pb(ix[u][i]);
    for (int v : adj[u]) {
        if (!seen[v]) 
            dfs(v);
    }
}

int main () {
    scanf(" %d %d %d", &n, &f, &d);

    for (int i = 0; i < f; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 0; i < d; i++) {
        int a;
        scanf(" %d", &a);
        ix[a].pb(i);
        scanf(" %d %d", &sx[i], &gx[i]);
    }



    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            cur.clear();
            dfs(i);
            sort(cur.begin(), cur.end(), cmp);        

            int sum = 0;
            for (int j = 0; j < cur.size(); j++) {
                if (sum > gx[cur[j]]) {
                    break;
                } else {
                    if (sum + sx[cur[j]] <= gx[cur[j]]) {
                        sum += sx[cur[j]];
                    } else {
                        sum = gx[cur[j]] + 1;
                    }
                }
            }
            ans += sum;
        }
    }

    printf("%d\n", ans);
}





