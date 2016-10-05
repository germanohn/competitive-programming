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

const int MAX = 105;
const int inf = 1e9;
const double eps = 1e-6;

int n, r, m;
int d[MAX][MAX];
double me[10005][MAX];

double dp (int cost, int cont) {
    if (cost >= 0 && cont == 0) return 1;
    else if (cost == 0 && cont > 0) return 0;

    if (me[cost][cont] > -eps) return me[cost][cont];

    double ans = 0;
    for (int i = 1; i <= r; i++) {
        if (cost - i >= 0) {
            double aux = dp (cost - i, cont - 1);
            ans += ((double) 1 / r) * aux;
        }
    }

    return me[cost][cont] = ans;
}

void floyd () {
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
}

void clear () {
    for (int i = 0; i <= 10000; i++) 
        for (int j = 0; j <= n; j++) 
            me[i][j] = -1;
}

int main () {
    int t, cont = 1;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &r);
        clear ();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                scanf (" %c", &c);
                if (c == 'Y') d[i][j] = 1;
                else d[i][j] = inf;
            }
        }

        floyd ();
       
        int couple; 
        scanf ("%d", &couple);

        printf ("Case %d\n", cont++);
        while (couple--) {
            int a, b;
            scanf ("%d %d %d", &a, &b, &m);
            a--, b--;
            //printf ("a %d b %d d %d\n", a, b, d[a][b]);
            printf ("%lf\n", dp (m, d[a][b]));    
        }
        printf ("\n");
    }
}

