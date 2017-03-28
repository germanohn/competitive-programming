#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e2 + 5;
const int inf = 1e8;

int t, n, f, m, q, cont;
int d[5 * N][5 * N];
map<pii, int> mp[5 * N];
vector<int> b[N];

void floyd() {
    for (int k = 0; k < cont; k++) 
        for (int i = 0; i < cont; i++) 
            for (int j = 0; j < cont; j++) 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void clean() {
    for (int i = 0; i < cont; i++) 
        mp[i].clear();
    for (int i = 0; i < n; i++)
        b[i].clear();
    cont = 0;
    memset(d, 0, sizeof d);
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        clean();
        scanf(" %d %d %d", &n, &f, &m);
        for (int i = 0; i < n; i++) {
            mp[i][pii(i, 1)] = cont++;
            b[i].pb(1);
            d[i][(i + 1) % n] = d[(i + 1) % n][i] = 1;
        }

        for (int i = 0; i < m; i++) {
            int bi, fi, bj, fj, w;
            scanf(" %d %d %d %d %d", &bi, &fi, &bj, &fj, &w);
            bi--, bj--;
            int &st = mp[bi][pii(bi, fi)];
            int &to = mp[bj][pii(bj, fj)];
            if (st == 0) 
                st = cont++, b[bi].pb(fi);
            if (to == 0) 
                to = cont++, b[bj].pb(fj); 
            d[st][to] = d[to][st] = w;
        }

        for (int i = 0; i < n; i++) {
            sort(b[i].begin(), b[i].end());
            for (int j = 0; j < b[i].size() - 1; j++) {
                int st = mp[i][pii(i, b[i][j])];
                int to = mp[i][pii(i, b[i][j + 1])];
                if (d[st][to])
                    d[st][to] = d[to][st] = min(d[st][to], abs(b[i][j] - b[i][j + 1]));
                else 
                    d[st][to] = d[to][st] = abs(b[i][j] - b[i][j + 1]);
            }
        }

        for (int i = 0; i < cont; i++) 
            for (int j = 0; j < cont; j++) 
                if (!d[i][j])
                    d[i][j] = inf;
        floyd();

        scanf(" %d", &q);
        while (q--) {
            int bi, fi, bj, fj;
            pii st, to;
            scanf(" %d %d %d %d", &bi, &fi, &bj, &fj);
            bi--, bj--;
            int li, lj, ri, rj, ans = INT_MAX;

            ri = upper_bound(b[bi].begin(), b[bi].end(), fi) - b[bi].begin();
            li = ri - 1;
            if (ri == b[bi].size())
                ri = li;

            rj = upper_bound(b[bj].begin(), b[bj].end(), fj) - b[bj].begin();
            lj = rj - 1;
            if (rj == b[bj].size())
                rj = lj;

            for (int i = 0; i < 4; i++) {
                int x = (i & 1) ? ri : li;
                int y = ((i >> 1) & 1) ? rj : lj;
                int u = mp[bi][pii(bi, b[bi][x])];
                int v = mp[bj][pii(bj, b[bj][y])];
                ans = min(ans, abs(fi - b[bi][x]) + d[u][v] + abs(fj - b[bj][y]));
            }
            if (bi == bj)
                ans = min(ans, abs(fi - fj));

            printf("%d\n", ans);
        }
    }
}

