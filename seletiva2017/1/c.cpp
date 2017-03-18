#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e2 + 5;

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

int main () {
    scanf(" %d", &t);
    while (t--) {
        cont = 0;
        scanf(" %d %d %d", &n, &f, &m);
        for (int i = 0; i < n; i++) {
            mp[i][pii(i, 1)] = cont++;
            b[i].pb(1);
            d[i][i + 1] = 1;
        }
        d[n - 1][0] = 1;

        for (int i = 0; i < m; i++) {
            int bi, fi, bj, fj, w;
            scanf(" %d %d %d %d %d", &bi, &fi, &bj, &fj, &w);
            bi--, bj--;
            pii st = pii(bi, fi), to = pii(bj, fj);
            if (mp[bi][st] == 0) 
                mp[bi][st] = cont++, b[bi].pb(fi);
            if (mp[bj][to] == 0) 
                mp[bj][to] = cont++, b[bj].pb(fj); 
            d[mp[bi][st]][mp[bj][to]] = w;
        }

        for (int i = 0; i < n; i++)
            sort(b[i].begin(), b[i].end());

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
                int x = ( i&1 )? ri:li;
                int y = ( (i>>1)&1 )? rj:lj;
                int u = mp[bi][pii(bi, x)];
                int v = mp[bj][pii(bj, y)];
                ans = min(ans, abs(fi - b[bi][x]) + d[u][v] + abs(fj - b[bj][y]));
            }
            if (bi == bj)
                ans = min(ans, abs(fi - fj));

            printf("%d\n", ans);
        }
    }
}

