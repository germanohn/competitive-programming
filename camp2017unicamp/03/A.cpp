#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int M = 505;

int n, m;
char g[N][N], s[M];
bool visi[N][N];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

int calc(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    if(visi[i][j]) return (g[i][j]-'0')/2;
    visi[i][j] = 1;
    return g[i][j]-'0';
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c", &g[i][j]);
    scanf(" %s", s);
    int i, j;
    i = 0; j = 0;
    int p = 0;
    int ans = 0;
    for(int k = 0; s[k]; k++){
        if(s[k] == 'L') p = (p+4-1)%4;
        else if(s[k] == 'R') p = (p+1)%4;
        else {
            int ni, nj;
            ni = i + di[p];
            nj = j + dj[p];
            if(p == 0) {
                ans += calc(i, j);
                ans += calc(i-1, j);
            }
            else if(p == 1) {
                ans += calc(i, j);
                ans += calc(i, j-1);
            }
            else if(p == 2) {
                ans += calc(i, j-1);
                ans += calc(i-1, j-1);
            }
            else {
                ans += calc(i-1, j);
                ans += calc(i-1, j-1);
            }
            i = ni;
            j = nj;
        }
    }
    printf("%d\n", ans);
}

