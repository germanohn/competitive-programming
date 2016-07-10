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

const int inf = 1e6;
const int MAX = 100;

int n, turn;
char worm[MAX], s[MAX];
int me[MAX][MAX][MAX], vis[MAX][MAX][MAX];
set<char> orig;
vector<pcc> rules[MAX];

int dp (int i, int j, char ch) {
    if (i == j) {
        if (ch == worm[i]) return 0;
        else return inf;
    }
    if (vis[i][j][ch] == turn) return me[i][j][ch];
    vis[i][j][ch] = turn;
    int ans = inf;
    for (int k = 0; k < rules[ch].size (); k++) {
        pcc cell = rules[ch][k];
        for (int mid = i; mid < j; mid++) 
            ans = min (ans, 1 + max (dp (i, mid, cell.ff), dp (mid+1, j, cell.ss))); 
    }
    return me[i][j][ch] = ans;
}

void clear () {
    turn++;
    orig.clear ();
    for (int i = 'A'; i <= 'T'; i++)
        rules[i].clear ();
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        clear ();
        for (int i = 0; i < n; i++) {
            scanf (" %s", s);
            rules[s[0]].pb (pii (s[1], s[2]));
            orig.insert (s[0]);
        }
        scanf (" %s", worm);
        int len = strlen (worm);
        if (len == 1) {
            printf ("0\n");
            continue;
        }
        int ans = INT_MAX;
        for (set<char>::iterator it = orig.begin (); it != orig.end (); it++) 
            ans = min (ans, dp (0, len-1, *it));
        if (ans >= inf)
            printf ("-1\n"); 
        else
            printf ("%d\n", ans);
    }
}

