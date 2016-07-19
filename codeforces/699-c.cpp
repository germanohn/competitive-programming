#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 105;
const int inf = 1e9;

int n;
int v[MAX];
int me[MAX][4][4];

int dp (int i, int gym, int contest) {
    if (i == n) return 0;
    if (me[i][gym][contest] != -1) return me[i][gym][contest];
    int ans = inf;
    if (v[i] == 0) {
        ans = min (ans, dp (i+1, 0, 0) + 1);
    } else if (v[i] == 1) {
        if (contest < 1) ans = min (ans, min (dp (i+1, 0, contest+1), dp (i+1, 0, 0) + 1));
        else ans = min (ans, dp (i+1, 0, 0) + 1); 
    } else if (v[i] == 2) {
        if (gym < 1) ans = min (ans, min (dp (i+1, gym+1, 0), dp (i+1, 0, 0) + 1));
        else ans = min (ans, dp (i+1, 0, 0) + 1);
    } else {
        if (gym < 1 && contest < 1) 
            ans = min (ans, min (dp (i+1, gym+1, 0), min (dp (i+1, 0, 0) + 1, dp (i+1, 0, contest+1))));
        else if (gym < 1 && contest == 1)
            ans = min (ans, min (dp (i+1, gym+1, 0), dp (i+1, 0, 0) + 1));
        else if (contest < 1 && gym == 1)
            ans = min (ans, min (dp (i+1, 0, contest+1), dp (i+1, 0, 0) + 1));
        else 
           ans = min (ans, dp (i+1, 0, 0) + 1); 
    }
    return me[i][gym][contest] = ans;
}

int main () {
    scanf ("%d", &n);
    memset (me, -1, sizeof me);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    printf ("%d\n", dp (0, 0, 0));
}

