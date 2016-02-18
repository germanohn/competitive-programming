#include <bits/stdc++.h>
using namespace std;

int moeda[1005], v, m;
int dp[2][100005];

/*bool dp (int i, int s) {
    if (s == v) return true;
    if (i == m) return false;
    if (me[i][s] != -1) return me[i][s];
    if (s + moeda[i] <= v) return me[i][s] = dp (i+1, s) + dp (i+1, s + moeda[i]);
    return me[i][s] = dp (i+1, s);
}*/

int main () {
    scanf ("%d %d", &v, &m);
    for (int i = 0; i < m; i++) 
        scanf ("%d", &moeda[i]);
    for (int i = m; i >= 0; i--) {
        for (int j = 0; j <= v; j++) {
            if (j == 0) dp[0][j] = 1;
            else if (i == m) dp[0][j] = 0; 
            else {
                if (j-moeda[i] >= 0) dp[0][j] = max (dp[1][j], dp[1][j-moeda[i]]);            
                else dp[0][j] = dp[1][j];
            }
        }
        for (int l = 0; l <= v; l++) 
            dp[1][l] = dp[0][l];
    }
    if (dp[0][v] > 0) printf ("S\n");
    else printf ("N\n");
}
