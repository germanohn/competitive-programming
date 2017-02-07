#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 606;
const int K = 55;
const int inf = INT_MAX;
int n, k, c[N][N], in[N][N], memo[N][N][K], visi[N][N][K];

int dp(int i, int j, int k) {
    if(k == 0) return 0;
    if(i == n) return -inf;
    int &me = memo[i][j][k];
    if(visi[i][j][k]) return me;
    visi[i][j][k] = 1;
    return me = max(c[j][i] + dp(i+1, i+1, k-1), dp(i+1, j, k));
}

void show(int i, int j, int k) {
    if(k == 0) return;
    int p = c[j][i] + dp(i+1, i+1,  k-1);
    int np = dp(i+1, j, k);
    if(p >= np) { 
        printf("%d ", i+1);
        show(i+1, i+1, k-1);
    } else show(i+1, j, k);
}
    
int main () {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            scanf("%d", &in[i][j]);
    
    for(int k = 0; k < n; k++) {
        for(int i = k; i < n; i++) {
            if(i) c[k][i] += c[k][i-1];
            for(int j = i+1; j < n; j++) {
                c[k][i] += in[i][j];
                c[k][j] -= in[i][j];
            }
        }
    }

    dp(0, 0, k);
    show(0, 0, k);
}

