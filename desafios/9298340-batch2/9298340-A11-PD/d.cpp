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

const int MAX = 505;

int n;
int t[MAX], adj[MAX][MAX];
int d[MAX][MAX];
ll ans[MAX];


void floyd () {
    for (int l = 0; l < n; l++) { 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) { 
                d[t[i]][t[j]] = min (d[t[i]][t[j]], d[t[i]][t[l]] + d[t[l]][t[j]]);
            }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= l && j <= l)
                    ans[l] += d[t[i]][t[j]];
            }
        }
    }
}

int main () {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf (" %d", &d[i][j]);

    for (int i = 0; i < n; i++) {
        int b, tmp;
        scanf (" %d", &b);
        b--;
        t[n-1-i] = b;
    }

    floyd ();

    for (int i = n-1; i >= 0; i--) 
        printf ("%lld ", ans[i]);
    printf ("\n");
}
