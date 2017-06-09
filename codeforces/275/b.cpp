#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;

int n, m;
int grid[N][N];
vector<pii> black;

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'B') 
                black.pb(pii(i, j));
        }
    }

    bool ans = true;
    for (int i = 0; ans && i < black.size(); i++) {
        for (int j = 0; ans && j < black.size(); j++) {
            if (i == j) continue;
            pii a, b;
            a = black[i], b = black[j];
            if (a.ff == b.ff && a.ss != b.ss) {
                if (a.ss > b.ss) swap(a, b);
                for (int col = a.ss; col <= b.ss; col++) 
                    if (grid[a.ff][col] == 'W')
                        ans = false;
            } else if (a.ff != b.ff && a.ss == b.ss) {
                if (a.ff > b.ff) swap(a, b);
                for (int row = a.ff; row <= b.ff; row++)
                    if (grid[row][a.ss] == 'W')
                        ans = false;
            } else {
                if (a.ss > b.ss) swap(a, b);
                int dx[2] = {a.ff, b.ff};
                int dy[2] = {b.ss, a.ss};
                int cont = 0;
                if (a.ff < b.ff) {
                    for (int k = 0; k < 2; k++) {
                        bool appear = false;
                        for (int col = a.ss; !appear && col <= b.ss; col++)
                            if (grid[dx[k]][col] == 'W')
                                appear = true;
                        for (int row = a.ff; !appear && row <= b.ff; row++) 
                            if (grid[row][dy[k]] == 'W')
                                appear = true;
                        if (appear) cont++;
                    }
                } else {
                    for (int k = 0; k < 2; k++) {
                        bool appear = false; 
                        for (int col = a.ss; !appear && col <= b.ss; col++) {
                            if (grid[dx[k]][col] == 'W')
                                appear = true;
                        }
                        for (int row = a.ff; !appear && row >= b.ff; row--) {
                            if (grid[row][dy[k]] == 'W')
                                appear = true;
                        }
                        if (appear) cont++;
                    } 
                }
                if (cont == 2) 
                    ans = false;
            }
        }
    }

    if (ans) printf("YES\n");
    else printf("NO\n");
}
