#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int t, n, k;
int x[N], y[N], c[N];
int p[N];
int bit[N];
multiset<int> ms[N];
map<int, int> mp;

void update(int idx, int val) {
    for (int i = idx; i < N; i += i & -i)
        bit[i] += val;
}

int query(int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i)
        ans += bit[i];
    return ans;
}

bool cmpY(int a, int b) {
    if (y[a] != y[b]) return y[a] > y[b];
    return x[a] < x[b];
}

bool cmpX(int a, int b) {
    if (x[a] != x[b]) return x[a] < x[b];
    return y[a] < y[b];
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &k);
        for (int i = 0; i < n; i++)
            ms[i].clear();

        for (int i = 0; i < n; i++) {
            scanf(" %d %d %d", &x[i], &y[i], &c[i]);
            p[i] = i;
        }

        sort(p, p + n, cmpX);
       
        int cont = 1;
        for (int i = 0; i < n; i++) {
            if (mp[x[p[i]]] == 0) 
                mp[x[p[i]]] = cont++;
        }

        for (int i = 0; i < n; i++) {
            ms[c[p[i]]].insert(mp[x[p[i]]]);
        }

        // inicializa bit
        for (int i = 0; i < n; i++) {
            update(mp[x[p[i]]], 1);
        }

        sort(p, p + n, cmpY);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l, r;
            int cur = p[i];
            update(mp[x[cur]], -1);
            ms[c[cur]].erase(ms[c[cur]].find(mp[x[cur]]));

            auto it = ms[c[cur]].upper_bound(mp[x[cur]]);
            if (it == ms[c[cur]].begin())
                l = 0;
            else 
                l = *prev(it);

            it = ms[c[cur]].lower_bound(mp[x[cur]]);
            if (it == ms[c[cur]].end())
                r = n;
            else
                r = *it;

            //printf("l %d r %d x %d y %d cur %d c %d\n", l, r, mp[x[cur]], y[cur], cur, c[cur]);
            //printf("q(r - 1) %d q(l) %d dif %d\n", query(r - 1), query(l), query(r - 1) - query(l));
            //printf("\n");
            ans = max(ans, query(r - 1) - query(l));
        }

        printf("%d\n", ans);
    }
}

