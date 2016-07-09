#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
#define LOSE 1
#define BACK 2
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 105;

int n, t, l, b, turn;
int val[MAX];
double me[MAX][MAX], vis[MAX][MAX];

double dp (int pos, int k) {
    if (pos == n) 
        return 1;
    else if (k <= 0) 
        return 0;
    if (vis[pos][k] == turn)
        return me[pos][k];
    vis[pos][k] = turn;
    double ans = 0;
    for (int i = 1; i <= 6; i++) {
        int nxPos;
        if (pos+i <= n)
            nxPos = pos+i;
        else if (pos+i > n) 
            nxPos = n - (pos+i-n); 

        if (val[nxPos] == LOSE) 
            ans += dp (nxPos, k-2)/6;
        else if (val[nxPos] == BACK)
            ans += dp (0, k-1)/6;
        else 
            ans += dp (nxPos, k-1)/6; 
    }
    return me[pos][k] = ans;
}

void clear () {
    turn++;
    for (int i = 0; i <= n; i++)
        val[i] = 0;
}

int main () {
    while (scanf ("%d %d %d %d", &n, &t, &l, &b)) {
        if (n == 0 && t == 0 && l == 0 && b == 0)
            break;
        clear ();
        for (int i = 0; i < l; i++) {
            int a;
            scanf ("%d", &a); 
            val[a] = LOSE;    
        }
        for (int i = 0; i < b; i++) {
            int a;
            scanf ("%d", &a);
            val[a] = BACK;
        }
        printf ("%lf\n", dp (0, t));
    }
}

