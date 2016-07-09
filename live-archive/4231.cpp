#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int inf = 1e9;
const int MAX = 85;

int n;
char worm[MAX], s[MAX];
int me[MAX][MAX][35];
vector<pcc> rules[MAX];

int dp (int i, int j, char ch) {
    if (i == j) {
        if (ch == worm[i])
            return 0;
        else 
            return inf;
    }
    ch -= 'A';
    if (me[i][j][ch] != -1) return me[i][j][ch];
    int ans = INT_MAX;
    for (int k = 0; k < rules[ch].size (); k++) {
        pcc cell = rules[ch][k];
        ans = min (ans, 1 + max (dp (cell.ff, i, k), dp (cell.ss, k+1, j)));        
    }
    return me[i][j][ch] = ans;
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        memset (me, -1, sizeof me);
        for (int i = 0; i < n; i++)
            rules[i].clear ();
        int maior = -1;
        for (int i = 0; i < n; i++) {
            scanf (" %s", s);
            rules[s[0]-'A'].pb (pii (s[1], s[2]));
            maior = max (maior, s[0]-'A');
        }
        printf ("maior %d\n", maior);
        int ans = INT_MAX;
        for (int i = 0; i <= maior; i++) {
            ans = min (ans, dp (0, n-1, i+'A'));
        }
        scanf (" %s", worm);
    }
}

