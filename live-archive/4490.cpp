#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;
const int inf = 1e5;

int n, k, turn;
int me[MAX][MAX][300][15], visi[MAX][MAX][300][15];
int mark[10], v[MAX];

int dp (int i, int j, int s, int l) {
    if (j < 0) return inf;
    if (i == n) {
        //else {
            int ans = 0;
            for (int num = 0; num < 8; num++) {
                if (mark[num] && !(s & (1 << num))) 
                    ans++; 
            }
            return ans;
        //}
    }
    if (visi[i][j][s][l] == turn) return me[i][j][s][l];
    visi[i][j][s][l] = turn;
    int ans, fixa, remove;
    fixa = (v[i] != l) + dp (i+1, j, s | (1 << v[i]), v[i]);
    remove = dp (i+1, j-1, s, l);
    ans = min (fixa, remove);
    return me[i][j][s][l] = ans;

}

int main () {
    int t = 1;
    while (scanf ("%d %d", &n, &k)) {
        turn++;
        if (n == 0 && k == 0) 
            break;
        for (int i = 0; i < 8; i++)
            mark[i] = false;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            v[i] -= 25;
            mark[v[i]] = true;
        }
        printf ("Case %d: %d\n\n", t++, dp (0, k, 0, 10)); 
    }
}

