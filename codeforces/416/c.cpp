#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

struct group {
    int c, p, id;
};

int n, k;
set<pii> table;
group vis[MAX];
vector<pii> ans;

bool cmp(group a, group b) {
    if (a.p != b.p) return a.p > b.p;
    return a.c < b.c;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &vis[i].c, &vis[i].p);
        vis[i].id = i + 1;
    }
    sort(vis, vis + n, cmp);
    scanf(" %d", &k);
    for (int i = 0; i < k; i++) {
        int r;
        scanf(" %d", &r);
        table.insert(pii(r, i + 1));
    }
    int m = 0, s = 0;
    for (int i = 0; i < n; i++) {
        auto it = table.lower_bound(pii(vis[i].c, 0));
        if (it == table.end()) continue;
        pii nx = *it;
        table.erase(it);
        m++, s += vis[i].p; 
        ans.pb(pii(vis[i].id, nx.ss));
    }
    printf("%d %d\n", m, s);
    for (pii cur : ans) 
        printf("%d %d\n", cur.ff, cur.ss);
}

