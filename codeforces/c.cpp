#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 100005;

int n;
ll cost[MAX];
ll me[MAX][4];
vector<string> dic, inv;

void revert (char* str) {
    int len = strlen (str);
    for (int i = 0; i < len/2; i++)
        swap (str[len-1-i], str[i]);
}

ll dp (int i, bool invert) {
    if (i == n) return 0;
    if (me[i][invert] != -1) return me[i][invert];
    int sinal1, sinal2;
    ll ans = 1e16;
    if (invert) {
        sinal1 = inv[i-1].compare (dic[i]);
        sinal2 = inv[i-1].compare (inv[i]);
        if (sinal1 <= 0) ans = min (ans, dp (i+1, 0));
        if (sinal2 <= 0) ans = min (ans, cost[i] + dp (i+1, 1));
    } else {
        sinal1 = dic[i-1].compare (dic[i]);
        sinal2 = dic[i-1].compare (inv[i]);
        if (sinal1 <= 0) ans = min (ans, dp (i+1, 0));
        if (sinal2 <= 0) ans = min (ans, cost[i] + dp (i+1, 1));
    }
    return me[i][invert] = ans;
}

int main () {
    memset (me, -1, sizeof me);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        cin >> cost[i];
    char s[MAX];
    for (int i = 0; i < n; i++) {
        scanf (" %s", s);
        dic.pb (s);
        revert (s);
        inv.pb (s);
    }
  /*  printf ("\noi\n");
    for (int i = 0; i < n; i++) 
        cout << dic[i] << ' ';
    printf ("\n");
    for (int i = 0; i < n; i++) 
        cout << inv[i] << ' ';
        */
    ll ans = min (dp (1, 0), cost[0] + dp (1, 1));
    if (ans == 1e16) printf ("-1\n");
    else cout << ans << endl;
}
