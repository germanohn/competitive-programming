#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 123;

char g[N][N];
int n, m;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c", &g[i][j]); 

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int h = g[i][j] - '0';
            ans += h * 6  - (max(2 * h - 2, 0));
            for(int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int hn = g[ni][nj] - '0';
                    if(hn > h) ans -= 2*h;
                    else if(hn == h) ans -= h;
                }
            }
        }
    }
    printf("%d\n", ans);
}

