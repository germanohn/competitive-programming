#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;

int n, m;
char s[105];
char g[N][N];

int si, sj, ei, ej;
int p[4] = {0, 1, 2, 3};
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

bool can(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '#';
}

bool valid() {
    int i = si, j = sj;
    for (int k = 0; s[k]; k++) {
        int d = s[k] - '0';
        i += di[p[d]];
        j += dj[p[d]];
        if (!can(i, j)) return false;
        if (i == ei && j == ej) return true;
    }
    return false;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (g[i][j] == 'E') {
                ei = i;
                ej = j;
            }
        }
    }
    scanf(" %s", s);

    int ans = 0;
    do {
        if (valid()) 
            ans++;
    } while (next_permutation(p, p + 4));

    printf("%d\n", ans);
}

