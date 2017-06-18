#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int inf = 600;

int n, m;
int g[N][N];
int t[N][N];
vector<pii> ans;

int main () {
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &g[i][j]);
        }
    }

    if (m > n) {
        for (int i = 0; i < n; i++) {
            int _min = inf;
            for (int j = 0; j < m; j++) {
                _min = min(_min, g[i][j]);
            }
            
            for (int j = 0; j < m; j++) 
                t[i][j] += _min;
            while (_min--) {
                ans.pb(pii(0, i + 1));
            }
        }

        for (int j = 0; j < m; j++) {
            int cur = g[0][j] - t[0][j];
            for (int i = 0; i < n; i++) {
                if (t[i][j] + cur != g[i][j]) { 
                    printf("-1\n");
                    return 0;
                }
            }

            while (cur--) {
                ans.pb(pii(1, j + 1));
            }
        }
    } else {
        for (int j = 0; j < m; j++) {
            int _min = inf;
            for (int i = 0; i < n; i++) {
                _min = min(_min, g[i][j]);
            }

            for (int i = 0; i < n; i++) 
                t[i][j] += _min;
            while (_min--) {
                ans.pb(pii(1, j + 1));
            }
        }

        for (int i = 0; i < n; i++) {
            int cur = g[i][0] - t[i][0];
            for (int j = 0; j < m; j++) {
                if (t[i][j] + cur != g[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }

            while (cur--) {
                ans.pb(pii(0, i + 1));
            }
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].ff == 0) {
            printf("row %d\n", ans[i].ss);
        } else {
            printf("col %d\n", ans[i].ss);
        }
    }
}

